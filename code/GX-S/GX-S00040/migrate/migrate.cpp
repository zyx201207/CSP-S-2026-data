#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,h=1,en;
long long x[2000005];
void f(long long o,long long sum,long long min){
	for(long long be=o;be<en;be++){
		sum++;
		if(x[en]-x[be]<=d){
			if(min>sum){
				min=sum;
				h=1;
			}
			if(min==sum){
				h++;
			}
			return;
		}
		for(long long i=1;i<n;i++){
			if(x[en]-x[be+i]>d){
				break;
			}
			if(x[en]-x[be+i]<=d){
				f(be+i,1,min);
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		h=0;
		cin>>n>>d;
		for(long long i=0;i<n;i++){
			cin>>x[i];
		}
		for(en=n-1;en>0;en--){
			for(long long be=0;be<en;be++){
				if(x[en]-x[be]<=d){
					break;
				}
				for(long long i=1;i<n;i++){
					if(x[en]-x[be+i]>d){
						break;
					}
					if(x[en]-x[be+i]<=d){
						f(be+i,1,LONG_LONG_MAX);
					}
				}
				if(h==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
