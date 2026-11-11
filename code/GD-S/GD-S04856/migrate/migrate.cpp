#include<bits/stdc++.h>
using namespace std;
long long num[2000005],e[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long c,t,n,d;
	cin>>c>>t;
	long long e=0;
	int flag=1;

	
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++)cin>>num[j];
		e=0;
		for(int st=0;st<n;st++){
			for(int en=st+2;en<=n;en++){
			flag=1;
			for(int i=st;i<en-1;i++){
				if(num[i+1]-num[i]>d)flag=0;
			}
				
			if(flag){
				if((num[en]-num[st])/2+1==d && (num[en]-num[st])==d+d-1){
				e++;
				}
			}
		}
		}
		cout<<e<<endl;
		
	}
	
	
	return 0;
}
