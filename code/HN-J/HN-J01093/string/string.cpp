#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
long long b[200005];
char t[200005];
char c[200005];
long long l,r,ans;
long long cnt;
long long q,mi,ma;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>b[i]>>t[i];
		if(t[i]==t[i-1]){
			a[cnt]+=b[i];
		}else{
			cnt++;
			a[cnt]=b[i];
			c[cnt]=t[i];
		}
	}
	l=1;
	r=cnt;
	long long z=0;
	while(l<r){
		if(l+1==r){
			a[l]=a[r];
		}
		z=abs(a[l]-a[r]);
		ma=max(a[l],a[r]);
		if(c[l]!=c[r]){
//			cout<<z;
			if(q>=ma){
				q-=ma;
				ans+=q;
			}else{
				ans+=ma-q;
				q+=ma-q;
			}
		}else{ 
			if(q>=z){
				q-=z;
				ans+=q;
			}else{
				ans+=z-q;
				q=z-q;
			}
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 

/*
6
1000000000 a
1000000000 a
1000000000 b
1000000000 a
1000000000 b
1000000000 b
*/



