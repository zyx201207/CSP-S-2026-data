#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const int M=3e5+10;
const int Inf=INT_MAX>>1;
int nn,n,m,aa[N],a[N],b[M],c[M],o[N],l[M],r[M],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>nn>>m;
	for(int i=1;i<=nn;i++){
		cin>>aa[i];
		if(aa[i]!=aa[i-1]) a[++n]=aa[i];
		else r[aa[i]]++;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		l[a[i]]=i;r[a[i]]++;
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag){
		int ss=0;
		for(int i=1;i<=n;i++){
			ss+=r[a[i]];c[a[i]]=ss;
		}
		for(int i=1;i<=m;i++) cout<<c[i]<<" ";
		return 0;
	}
	for(int i=1;i<=m;i++) b[i]=Inf;
//	for(int i=1;i<=n;i++) p[i]=l[a[i]];
	for(int i=1;i<=m;i++){
		t=0;
		for(int j=l[i];j<=n;j++){
			if(b[a[j]]<=t&&o[b[a[j]]]==a[j]) t=b[a[j]];
			else b[a[j]]=++t,o[t]=a[j];
		}
		for(int j=1;j<=m;j++){
			if(b[j]<=t&&o[b[j]]==j) c[j]+=r[i];
			b[j]=Inf;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
