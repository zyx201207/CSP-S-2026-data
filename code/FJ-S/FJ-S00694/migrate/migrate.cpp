#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=b;i++){
		long long c,d,l[200005];
		cin>>c>>d;
		for(int j=1;j<=c;j++){
			cin>>l[j];
		}int sum=0,ans=0,cnt=0;
		for(int kk=1;kk<=c;kk++)
		for(int j=kk;j<=c;j++){
			
			if(l[j]-l[kk]>d){
				long long kfc=l[j]-l[kk]-d;
				for(int z=kk;z<j;z++){
					if(l[z]-l[kk]>=kfc&&l[j]-l[z]<=d&&l[z]-l[kk]<=d){
					
						ans++;
					}
				}
				if(ans==2){
			
					cnt++;
					
				}
			}ans=0;
		}cout<<cnt<<"\n";
	}
	return 0;
}  
