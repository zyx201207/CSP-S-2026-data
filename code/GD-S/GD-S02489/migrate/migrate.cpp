#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,cnt;
long long x[2000005];
long long dasz;
long long da[2000005];
long long cssz;
long long cs[2000005],pd;
void f(long long a,long long b){
	cssz++;
	cs[cssz]=a;
	if(a==b){
		if(dasz>cssz){
			dasz=cssz;pd=0;
			for(int i=1;i<=dasz;i++){
				da[i]=cs[i];
			}
		}
		else if(dasz==cssz) pd++;
	}
	for(int i=a+1;i<=b;i++){
		if(x[i]-x[a]<=d){
			f(i,b);
		}
		else break;
	}
	cssz--;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cssz=0;
				dasz=1e18;
				pd=0;
				f(i,j);
				if(pd==1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
