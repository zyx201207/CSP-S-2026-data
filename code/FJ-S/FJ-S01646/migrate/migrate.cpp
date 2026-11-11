#include<bits/stdc++.h> 
using namespace std;
const long long N=2e6+10;
long long x[N],cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		cnt=0;
		for(int i=1;i<=n;i++)
		cin>>x[i];
		int kd=2*d;
		int cha=x[2]-x[1];
		for(int b=1;b+d/cha+1<=n;++b){
			int e=b+d/cha+1;
			int e2=b+kd/cha;
			cnt+=(e2-e)/cha;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
