#include<iostream>
using namespace std;
int a[500005];
int t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=true;
			for(int k=j;k>=i;k--){
				for(int l=j;l<=n;l++){
					if(a[k]==a[l]){
						flag=false;
						break;
					}
				}
				if(!flag) break;
			}
			if(flag) t[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
