#include<bits/stdc++.h>
using namespace std;
bool vis[300001];
struct tree{
	int deep=0,num=0,fa=0;
}a[300001];
bool cmd(tree x,tree y){
	if(x.deep!=y.deep)return x.deep>y.deep;
	else return x.num<y.num;
}
int f[300001];
int b[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,shu=0,sum=0,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(f[b[i]]==0)shu++;
		f[b[i]]++;
		a[b[i]].num=b[i];
	}
	vis[b[n]]=1;
	a[b[n]].deep=1;
	a[b[n]].fa=0;
	for(int i=n-1;i>=1;i--){
		if(!vis[b[i]]){
			vis[b[i]]=1;
			a[b[i]].fa=b[i+1];
			a[b[i]].deep=a[b[i+1]].deep+1;
			sum++;
			if(sum>=shu)break;
		}
	}
	sort(a+1,a+m+1,cmd);
	for(int i=1;i<=m;i++)f[a[i].fa]+=f[a[i].num];
	for(int i=1;i<=m;i++)cout<<f[i]<<" ";
	return 0;//freopen("card1.in","r",stdin);
}
