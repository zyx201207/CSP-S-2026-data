#include<bits/stdc++.h>
using namespace std;
long long n,n1,ans=0,l=1,r;
struct{
	long long x;
	char y;
}a[200010];
void check(int z){
	long long sum=0,a1=a[l].x,a2=a[r].x,b1=a1,b2=a2;
	char c1=a[l].y,c2=a[r].y;
	while(l!=r){
		if(b1>n1){
			if(c1!=c2) ans+=a2;
			cout<<ans;
			return;
		}else if(b2>n1){
			if(c1!=c2) ans+=a1;
			cout<<ans;
			return;
		}
		if(a1==a2){
			if(c1!=c2) ans+=a1;
			l++;
			r--;
			a1=a[l].x;
			c1=a[l].y;
			a2=a[r].x;
			c2=a[r].y;
			b1+=a1;
			b2+=b2;
		}else if(a1>a2){
			if(c1!=c2) ans+=a2;
			a1=a1-a2;
			r--;
			a2=a[r].x;
			c2=a[r].y;
			b2+=a2;
		}else{
			if(c1!=c2) ans+=a1;
			a2=a2-a1;
			l++;
			a1=a[l].x;
			c1=a[l].y;
			b1+=a1;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		ans+=a[i].x;
	}
	r=n;
	n1=ans/2;
	ans=0;
	check(1);
	return 0;
}
