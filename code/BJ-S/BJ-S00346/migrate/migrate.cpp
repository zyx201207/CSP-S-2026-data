#include<bits/stdc++.h>
using namespace std;
long long x[2000010],c[2000010],ok[2000010];
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
int cc,t;
cin>>cc>>t;
while(t--){
	int n;
	long long d;
	cin>>n;
	cin>>d;
	for(int i=0;i<n;i++){
		cin>>x[i];
		}
	for(int i=0;i<n-1;i++){
		c[i]=x[i+1]-x[i];
		}
	for(int i=0;i<n;i++){
		if(i>=n-3||c[i+2]>d||c[i+1]>d||c[i]>d){
			ok[i]=-1;
			continue;
			}
		if((c[i]+c[i+1]<=d&&c[i+1]+c[i+2]<=d&&c[i]+c[i+1]+c[i+2]>d){
			ok[i]=1;
			}
		else{
			ok[i]=0;
			}
	}
	long long l=0,r=0,ans=0;
	int f=0;
	for(int i=0;i<n;i++){
		if(ok[i]==0){
			r++;
		}
		if(ok[i]==1){
			if(f==0){
				f=1;
				}
			else{
			ans+=l*r+l+r+1;
			}
			l=r;
			r=0;
		}
		if(ok[i]==-1){
			if(f==1){
			ans+=l*r+l+r+1;
			f=0;
			}
			l=0;
			r=0;
		}
	}
	
	for(int i=0;i<n;i++){
		if(i>=n-5||c[i+4]>d||c[c+3]>d||c[i+2]>d||c[i+1]>d||c[i]>d){
			ok[i]=-1;
			continue;
			}
		if((c[i]+c[i+1]+c[i+2]<=d&&c[i+2]+c[i+3]+c[i+4]<=d&&c[i]+c[i+1]+c[i+2]+c[i+3]+c[i+4]>2*d){
			ok[i]=1;
			}
		else{
			ok[i]=0;
			}
	}
	long long l=0,r=0;
	int f=0;
	for(int i=0;i<n;i++){
		if(ok[i]==0){
			r++;
		}
		if(ok[i]==1){
			if(f==0){
				f=1;
				}
			else{
			ans+=l*r+l+r+1;
			}
			l=r;
			r=0;
		}
		if(ok[i]==-1){
			if(f==1){
			ans+=l*r+l+r+1;
			f=0;
			}
			l=0;
			r=0;
		}
	}
	cout<<ans<<"\n";
}
fclose(stdin);
fclose(stdout);
return 0;