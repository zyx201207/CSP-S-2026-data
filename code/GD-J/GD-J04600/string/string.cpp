#include<bits/stdc++.h>
using namespace std;
long long n,s,cut,l,r,l1,r1,ans;
struct node{
	long long x;
	char y;
}a[200005],b[200005],c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		s+=a[i].x;
	}
	while(cut<s/2){
		l++;
		if(cut+a[l].x<=s/2){
			cut+=a[l].x;
			b[l].x=a[l].x;
			b[l].y=a[l].y;
		}else{
			b[l].x=s/2-cut;
			b[l].y=a[l].y;
			cut=s/2;
		}
	}
	cut=s;
	r=n+1;
	while(cut>s-s/2){
		r--;
		if(cut-a[r].x>=s-s/2){
			cut-=a[r].x;
			c[n-r+1].x=a[r].x;
			c[n-r+1].y=a[r].y;
		}else{
			c[n-r+1].x=cut-(s-s/2);
			c[n-r+1].y=a[r].y;
			cut=s-s/2;
		}
	}
	r=n-r+1;
	l1=r1=1;
	while(l1<=l&&r1<=r){
		if(b[l1].y!=c[r1].y)ans+=min(b[l1].x,c[r1].x);
		if(c[r1].x>b[l1].x){
			c[r1].x-=b[l1].x;
			l1++;
		}else{
			b[l1].x-=c[r1].x;
			r1++;
		}
	}
	cout<<ans;
	return 0;
}
