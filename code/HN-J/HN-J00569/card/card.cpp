#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],a2[N],t[N];
struct tbc{
	int s,e;
};
void Co(){
	for(int j=1;j<=n;j++){
		if(a2[j]!=-1)t[a2[j]]++;
	}
	for(int j=1;j<=n;j++){
		cout<<t[a2[j]]<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a2[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		int vis[N],tmp=0;
		tbc bj[N];
		for(int j=1;j<=n;j++)a2[j]=a[j]; 
		for(int j=i;j<=n;j++){
			if(vis[a2[j]]==0&&a2[j]!=-1){
				vis[a2[j]]=1;
				bj[++tmp].s=j;
			}
			else{
				for(int k=bj[tmp].s;k<=j;k++)a2[k]=-1;
				vis[a[j]]=0;
			}
		}
		Co();
	}
	return 0;
}
