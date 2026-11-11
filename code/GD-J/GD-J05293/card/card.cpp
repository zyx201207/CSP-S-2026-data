#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<=2){
		int anss[3]={0,0,0};
		for(int i=1;i<=n;i++){
			if(a[i] != a[n]){
				anss[a[i]]++;
				anss[a[n]]++;
			}
			if(a[i]==a[n]){
				anss[a[i]]++;
			}
		}
		cout<<anss[1]<<' '<<anss[2];
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]++;	
	}
	for(int i=1;i<=m;i++){
		ans[i]+=ans[i-1];
		cout<<ans[i]<<' ';
	}
	return 0;
}
