#include<bits/stdc++.h>
using namespace std;
long long c,t;
const int MAXN=2000005;

long long d[MAXN];
long long n,m;
bool check_a(){
	long long sub=d[2]-d[1];
	for(int i=2;i<n;i++){
		if(sub!=d[i+1]-d[i]){
			return false;
		}
	}
	return true;
}
void solve_a(){//等差数列呈高斯求和 
	long long len=max(0LL,n-3);
	cout<<(len+1)*len/2<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>d[i];
		if(check_a()){//Subtesk-Alpha.
			solve_a();
			continue;
		}
	}
	return 0;
}
