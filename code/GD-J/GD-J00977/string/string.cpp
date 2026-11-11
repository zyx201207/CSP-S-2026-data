#include<bits/stdc++.h>
using namespace std;
long long n,m=1,b=1,v;
struct Q{
	long long q;
	char w;
}a[200005];
long long s,d,ans;
int main(){
	freopen("string.in","r","std.in");
	freopen("string.out","w","std.out");
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	v=n;
	for(long long i=1;i<=n;i++){
		long long qw;
		cin>>qw>>a[i].w;
		s+=qw;
		a[i].q=a[i-1].q+qw;
		if(i!=1){
			if(a[i].w!=a[i-1].w) m=0;
		}
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	d=s+1;
	for(long long i=1;i<=s/2;i++){
		d--;
		if(i<=a[b].q){
			if(d>a[v-1].q){
				if(a[b].w!=a[v].w){
					ans++;
				}
			}else{
				v--;
				if(a[b].w!=a[v].w){
					ans++;
				}
			}
		}else{
			b++;
			if(d>a[v-1].q){
				if(a[b].w!=a[v].w){
					ans++;
				}
			}else{
				v--;
				if(a[b].w!=a[v].w){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
