#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(int i=1,j=2;j<=n;){
			if(j-i<3){
				j++;
				continue;
			}
			else{
				long long l=a[j]-a[i];
				if(l>=d*2){
					i++;
					continue;
				}
				if(l<=d) {
					j++;
					continue;
				}
				int cnt=0,flag=1;
				for(int k=i+1;k<j;k++){
					long long l1=a[k]-a[i];
					if(l1<=d&&(l-l1)<=d) cnt++;
					if(cnt>=3) flag=0;
				}
				ans+=flag;
				i++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

