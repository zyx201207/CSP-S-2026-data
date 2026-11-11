#include<bits/stdc++.h>
using namespace std;
long long a[2000005]={};
long long dp[2000005],maxn;
bool flag2[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	int c,t;
	cin >> c >> t;long long  n,d;
	while(t--){
		long long cnt=0;
		cin >>n >> d;
		long long dao=0,maxd=0;
	    int sign; 
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			if(a[i-1]+d>=a[i]&&flag){
				sign=i;
			}
			else
			flag=false;
			double l=ceil(1.0*n/d);
			if(l==2&&flag){
				cnt+=1;
				flag2[sign]=false;
			}
			else{
				continue;
			}

		}cout<<cnt<<endl;
        }
	return 0;
} 

