#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],b[M];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;i++){
			if(b[a[i]]==1){
				memset(b,0,sizeof(b));
			}
			b[a[i]]++;
		}
		for(int j=i;j<=m;i++){
			ans[j]+=b[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
