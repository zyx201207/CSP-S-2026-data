#include<bits/stdc++.h>
using namespace std;
stack<char> d;
long long ans,n,b,v,m;
char c;
struct u{
	long x;
	char y;
}a[200005];
int u;
void g(long j,long k){
	if(j>=k) return;
	if(a[j].y==a[k].y){
		if(a[j].x>a[k].x){
			a[j].x-=a[k].x;
			g(j,k-1);
		}else if(a[j].x<a[k].x){
			a[k].x-=a[j].x;
			g(j+1,k);
		}else g(j+1,k-1);
	}
	if(a[j].y!=a[k].y){
		ans=ans+min(a[j].x,a[k].x);
		if(a[j].x>a[k].x){
			a[j].x-=a[k].x;
			g(j,k-1);
		}else if(a[j].x<a[k].x){
			a[k].x-=a[j].x;
			g(j+1,k);
		}else g(j+1,k-1);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(c!=a[i].y&&i!=1) m++;
		c=a[i].y;
	}
	if(m==0){
		cout<<0;
		return 0;
	}
	g(1,n);
	cout<<ans;
	return 0;
}
