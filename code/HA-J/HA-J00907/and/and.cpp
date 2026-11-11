#include<bits/stdc++.h>
using namespace std;
int w2(int m){
	int p=0,r=1;
	while(r<=m){
		r*=2;
		p++;
	}return p;
}
struct nt{
	int s;
	int w;
}a[200005];
bool cmp(nt x,nt y){
	if(x.w==y.w)return x.s<y.s;
	return x.w>y.w;
} 
int main(){
	int m,n;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].s;
	for(int i=1;i<=n;i++){
		a[i].w=w2(a[i].s); 
	}
	sort(a+1,a+1+n,cmp);
	long long ans=pow(2,10);
	for(int i=2;i<=m;i++){
		a[i].s=(a[i].s&a[i-1].s);
	}cout<<a[m].s<<endl;
	return 0;
}
