#include<iostream>
#define ll long long
using namespace std;
const int N=500005,M=300005;
int a[N],lst[M],nxt[N],c[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool fA=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1 && a[i-1]>a[i])fA=0;//不满足性质A 
		nxt[lst[a[i]]]=i;
		lst[a[i]]=i;
	}
	for(int i=n;i>=1;i--){//连续的直接跳过 
		if(nxt[i] && nxt[nxt[i]])nxt[i]=nxt[nxt[i]];
	}
//	for(int i=1;i<=n;i++)cout<<nxt[i]<<' ';
	if(fA){
		for(int i=n;i>=1;i--){
			if(!c[a[i]])c[a[i]]=i;
		}
		for(int i=1;i<=m;i++)cout<<c[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(nxt[j])j=nxt[j];
			c[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
}
/*
6 3
1 1 2 1 3 2
3 6 4
*/
/*
5 3
1 2 1 3 2
2 5 3
*/
/*
6 2
1 1 2 1 1 2
4 6
*/
