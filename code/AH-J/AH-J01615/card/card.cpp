#include<bits/stdc++.h>
using namespace std;
int ans[300005]={0},n,m,t=0;
bool b[300005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(t<n){
		for(int i=t;i<n;i++){
			if(b[a[i]]==0){
				b[a[i]]++;
			}
			else{
				for(int j=i-1;j>=0;j--){
					b[a[j]]=0;
					if(a[j]==a[i]){
						b[a[j]]=1;
						break;
					}
				}
			}
		}
		for(int i=t;i<n;i++){
			ans[a[i]]+=b[a[i]];
			b[a[i]]=0;
		}
		t++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
