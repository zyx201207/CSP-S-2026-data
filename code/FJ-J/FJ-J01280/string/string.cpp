#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=2e5;
int n,m;
struct A{
	int len;
	char s;
}a[N+5];
A b[N+5];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].s;
		b[n-i+1].len=a[i].len;
		b[n-i+1].s=a[i].s;
	}	
	a[0].len=0;
	int aa=1,bb=1,ans=0;
	while((aa<=n)&&(bb<=n)){
		if((aa==n)&&(bb==n)&&(a[n].len==0)&&(b[n].len==0))break;
		if(a[aa].len<=b[bb].len){
			if(a[aa].s==b[bb].s){
				b[bb].len-=a[aa].len;
				a[aa].len=0;
			}else{
				ans+=a[aa].len;
				b[bb].len-=a[aa].len;
				a[aa].len=0;
			}
		}else{
			if(a[aa].s==b[bb].s){
				a[aa].len-=b[bb].len;
				b[bb].len=0;
			}else{
				ans+=b[bb].len;
				a[aa].len-=b[bb].len;
				b[bb].len=0;
			}
		}
		if(a[aa].len==0)aa++;
		if(b[bb].len==0)bb++;
	}
	cout<<ans/2;
	return 0;
}
