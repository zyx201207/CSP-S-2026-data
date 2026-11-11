#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,m,t[N],fa[N];
bool flag[N];
void f(int x){
	t[x]++;
	if(fa[x]!=x)f(fa[x]);
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==1||i==j){
				memset(flag,0,sizeof(flag));
				memset(fa,0,sizeof(fa));
				fa[j]=a[j];				
			}
			else fa[j]=a[j-1];
			flag[a[j]]=1;
		}
		f(a[n]);
		memset(flag,0,sizeof(flag));
		memset(fa,0,sizeof(fa));
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
