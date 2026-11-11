#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10,M=3e5+10;

int n,m,Max[M],Min[M],a[N],st[N],top=0;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(Min,0,sizeof(Min));
		for(int j=i;j<=n;j++){
			if(Min[a[j]]==1){
				while(st[top]!=a[j]){
					Min[st[top]]=0;
					top--;
				}
			}
			else{
				Min[a[j]]=1;
				top++;
				st[top]=a[j];
			}
		}
		for(int j=i;j<=m;j++){
			if(Min[a[j]])Max[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<Max[i]<<" ";
	}
	return 0;
}
