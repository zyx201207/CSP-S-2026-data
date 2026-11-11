#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,r[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>r[i];
		int sum=0;
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				long long cnt=0,q=j-i,p=(j-i)/d/d;
				if(q%d!=0&&q>d){
					if(n/d%2!=0&&p!=0) sum++;
					else if(n/d%2==0) sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
