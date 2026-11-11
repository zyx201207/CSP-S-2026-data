#include<bits/stdc++.h>
using namespace std;
int n,m,card[500005],sum[300005],c[300005];
struct NODE{
	int book,cnt=0;
	int f[5005];
}a[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m>5000){
		for(int i=1;i<=n;i++){
			cin>>card[i];
			sum[card[i]]=i;
		}for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>card[i];
		a[card[i]].book=i;
		c[card[i]]++;
	}
	for(int i=1;i<=m;i++){
		int x=a[i].book;
		a[i].cnt++;
		a[i].f[a[i].cnt]=card[x];
		while(x!=n){
			x=a[card[x+1]].book;
			a[i].cnt++;
			a[i].f[a[i].cnt]=card[x];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=a[i].cnt;j++)sum[a[i].f[j]]+=c[i];
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
