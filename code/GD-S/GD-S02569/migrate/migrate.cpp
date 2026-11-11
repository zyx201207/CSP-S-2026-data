#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,jl,minn;
long long x[2000005];
long long l[2000005];
long long len[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ed=n;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<=d+1){
			cout<<"0"<<endl;
			continue;
		}
		for(long long i=1;i<n;i++){
			l[i]=abs(x[i+1]-x[i]);
			if(l[i]>d){
				ed=i-1;
				break;
			}
		}
		for(long long i=d+2;i<=ed;i++){
			len[i]=len[i-1]+l[i];
		}
		long long ans=0;
		for(long long z=d+2;z<=ed;z++){
			long long k=0;
			for(long long i=d+2;i<z;i++){
				if(len[i+1]-k>=d){
					minn++;
					k=len[i];
				}
			}
			int c=abs(d-(len[z]-k));
			if(len[z]-k<d||len[z]-k>d){
				minn++;
			}
			if(c==0){
				continue;
			}
			else{
				int cnt=0;
				for(long long i=d+2;i<=z;i++){
					if(l[i]<=c)cnt++;
				}
				if(cnt==2)ans++;
			}
		}
		for(long long z=d+3;z<=ed;z++){
			long long k=0;
			for(long long i=z;i<ed;i++){
				if(len[i+1]-k>=d){
					minn++;
					k=len[i];
				}
			}
			int c=abs(d-(len[ed]-k));
			if(len[ed]-k<d||len[ed]-k>d){
				minn++;
			}
			if(c==0){
				continue;
			}
			else{
				int cnt=0;
				for(long long i=z;i<=ed;i++){
					if(l[i]<=c)cnt++;
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
