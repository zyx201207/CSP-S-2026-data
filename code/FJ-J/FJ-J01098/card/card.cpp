#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int b[500005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int ii=1;ii<=n;ii++){
		
		int s=0;
		for(int i=ii;i<=n;i++){
			bool f=1;
			for(int j=1;j<=s;j++){
				if(b[j]==a[i]){
					s=j;
					f=0;
				}
			}
			if(f){
				b[++s]=a[i];
			}
		}
		for(int i=1;i<=s;i++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
