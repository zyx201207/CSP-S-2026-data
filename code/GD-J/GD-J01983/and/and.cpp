#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,b[1011],l[300008],fl,ans1;
struct tt{
	int x;
	int t[60];
}a[300008];
void cmp(int x,int j){
	int k=0,op=40;
	while(x){
		b[++k]=x%2;
		x/=2;
	}
	for(int i=1;i<=k;i++){
		a[j].t[op]=b[i];
		if(b[i]==1) l[op]++; 
		op--;
	}
}int cnp(tt x,tt y){
	for(int i=fl;i<=40;i++){
		if(x.t[i]!=y.t[i]) return x.t[i]>y.t[i];
	}return x.x>y.x;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		ans1=max(ans1,a[i].x);
		cmp(a[i].x,i);
	}
	if(m==1) cout<<ans1,exit(0);
	for(int i=1;i<=40;i++){
		if(l[i]>=m){
			fl=i;
			break;
		}
	}
	sort(a+1,a+n+1,cnp);
	ans=a[1].x;
	for(int i=2;i<=m;i++) ans=ans&a[i].x;
	cout<<ans;
}
