#include<bits/stdc++.h>
using namespace std;
int a[500001],b[300001],c[500001],n,m,s[500001],ss[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(b,-1,sizeof(b));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]!=-1)c[b[a[i]]]=i;
		b[a[i]]=i;
		s[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=0)s[c[i]]+=s[i];
		else s[i+1]+=s[i];
	}
	for(int i=1;i<=n;i++){
		ss[a[i]]=s[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ss[i]<<' ';
	}
	return 0;
}
