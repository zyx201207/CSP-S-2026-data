#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
bool flag[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int b[N],b1=0;
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=n;j++){
			if(!flag[a[j]]){
				b[++b1]=a[j];
				flag[a[j]]=true;
			}else{
				while(b1>=1 && b[b1]!=a[j]){
					flag[b[b1]]=false;
					b[b1--]=0;
				}
			}
		}
		for(int i=1;i<=b1;i++)
			ans[b[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
