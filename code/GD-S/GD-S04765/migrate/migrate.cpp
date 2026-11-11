#include<bits/stdc++.h>
using namespace std;
int c,t;
const long long MAXN=2000010;
long long n,d;
long long is[MAXN]={0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int ci=1;ci<=t;ci++){
		cin>>n>>d;
		for(long long i=1;i<=n-d-1;i++) cin>>is[i];
		long long sum=0;
		for(int i=1;i<=n;i++){
			long long gr=i+d+1;
			int f=1;
			for(int j=i+1;j<=n;j++){
				long long sum=0;
				if(is[j]-is[i]<=d){
					sum+=is[i+1]-is[i];i++;
				}
				if(sum>d){
					int cha=j-i;
					long long he=0;
					if(cha>=2){
						he=is[j]-is[i];
						if(he/d==1) sum++;
					}
					break;
				}
			} 
			if(f!=1) continue;
		}
		cout<<sum<<endl;
	} 
	return 0;
}
