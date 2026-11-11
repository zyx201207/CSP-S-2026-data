#include<bits/stdc++.h>
using namespace std;
struct L{
	int l,r,x;
	char c;
} a[400010];
int n,m=1;
long long ans=0;
bool cmp(L a,L b){
	if(a.l==b.l) return a.x<=b.x;
	return a.l<b.l;}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		a[i].l=m,a[i].r=m+a[i].x-1;
		m+=a[i].x;}
	m=1;
	int s=n;
	for(int i=n+1;i<=n+n;i++){
		a[i].x=a[s].x,a[i].c=a[s].c;
		s--;
		a[i].l=m,a[i].r=m+a[i].x-1;
		m+=a[i].x;}
	sort(a+1,a+n+n+1,cmp);
	for(int i=1;i<=n+n-1;i++){
		if(a[i].l==a[i+1].l){
			if(a[i].c!=a[i+1].c) ans+=a[i].x;
		}
		if(a[i].l<a[i+1].l){
			if(a[i].c!=a[i+1].c) ans+=a[i].r-a[i+1].l+1;
		}
	}
	ans/=2;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
