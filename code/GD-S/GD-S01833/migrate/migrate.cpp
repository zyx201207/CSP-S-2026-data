#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,num[2000005],ans;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		memset(num,0,sizeof(num));
		cin>>n>>d;
		num[1]=1,num[0]=1;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=2;i<=a[n];i++){
			if(i>d){
				bool flag=1;
				long long j=1;
				while(flag){
					if(a[j]>i-d){
						num[i]=num[a[j-1]];
						if(j%d!=0)num[i]++;
						flag=0;
					}else{
						j++;
					}
				}
			}else{
				num[i]=num[1];
			}
		}
		for(int i=1;i<=a[n];i++){
			if(num[i]==2){
				ans+=a[n]-i+1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
