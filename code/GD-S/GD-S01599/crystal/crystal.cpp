#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,a[N],c[N],s,m,x,mx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	x=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		c[i-1]=a[i]-a[i-1];
		if(c[i-1]<0) c[i-1]*=-1;
	}
	s=1;
	for(int i=1;i<n;i++){
		if(m>=c[i]*s){
			m-=(c[i]*s);
			s++;
			mx=max(mx,s);
		}else{
			m+=(a[i]-a[i-s+1]);
			if(m>=c[i]*s){
				m-=c[i]*s;
			}else{
				s--;
				i--;
				if(s==-1) break;
			}
			mx=max(mx,s);
		}
	}
	cout<<mx;
}
