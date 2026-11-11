#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,s,z;
	char y;
}a[200005];
bool cmp(node b,node c){
	if(b.y==c.y&&b.s==c.s){
		return b.z>c.z;
	}else if(b.y==c.y){
		return b.s<c.s;
	}
	return b.y<c.y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long t=0;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].s=t;
		t+=a[i].x;
		a[i].z=t-1;
	}
	long long t1;
	if(t%(long long)2==0){
		t1=t/(long long)2-1;
	}else{
		t1=t/(long long)2;
	}
	long long q=0;
	long long ans=t1+1;
	int o;
	for(int i=0;i<n;i++){
		if(a[i].z>t1&&a[i].s<=t1){
			long long m=a[i].s;
			a[i].s=t-1-a[i].z;
			a[i].z=t-1-m;
			long long g=a[i].z-t1+1;
			long long h=t1-a[i].s+1;
			ans-=min(g,h);
			o=i;
		}else if(a[i].z>t1&&a[i].s>t1){
			long long m=a[i].s;
			a[i].s=t-1-a[i].z;
			a[i].z=t-1-m;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n-1;i++){
		if(a[i].y==a[i+1].y){
			if(a[i].z>=a[i+1].s){
				long long w=a[i].z-a[i+1].s+1;
				ans-=w;
				a[i+1].s=min(a[i].s,a[i+1].s);
				a[i+1].z=max(a[i+1].z,a[i].z);
			}
		}
	}
	if(ans<0){
		cout<<0;
	}else{
		cout<<ans;
	}
	return 0;
}
