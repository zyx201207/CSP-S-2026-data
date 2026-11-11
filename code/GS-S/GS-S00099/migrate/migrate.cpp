#include <bits/stdc++.h>
using namespace std;
int a[2000010];

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	
	int c,t,n,d;
	int sta=0,lon1=0,lon2=0,sum=0;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		for(int i=1; i<n; i++){
			if(a[i]-a[i-1] < d){
				
				if(lon2!=1){
					lon1 = lon2;
					lon2 = i - sta;
					sta = i;
					sum += lon1*lon2;
				}else{
					sta = i;
					
				}
				
			}
		}
		lon1 = lon2;
		lon2 = n - sta;
		sum += lon1*lon2;
		cout<<sum<<endl;
	}
	return 0;
}
