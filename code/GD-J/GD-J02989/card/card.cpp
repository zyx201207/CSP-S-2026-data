#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
int s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		int x=1;
		s[x++]=a[i-1];
		for(int j=1;j<=m;j++){
			if(s[j]==a[i]){
				x=j;
			}
			s[x]=a[j];
			x++;
		}
		while(x){
			ans[s[x--]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}

