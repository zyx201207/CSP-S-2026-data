#include<bits/stdc++.h>
using namespace std;
int main(){
	freoprn("and.in","r",stdin);
	freoprn("and.out","w",stdout);
	long long n,m,a[200005],ans=0,p[32];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long k=a[i],o=0;
		while(k!=0){
			p[o]+=k%2;
			k/=2;
			o++;
		}
	}
	long long j=32,pd[200005];
	for(int i=1;i<=n;i++)pd[i]=1;
	while(1){
		for(int i=j;i>=0;i--){
			if(p[i]>=m){
				ans+=pow(2,i);
				j=i;
				if(i==0){
					cout<<ans;
					return 0;
				}
				break;
			}
			if(i==0){
				cout<<ans;
				return 0;
			}
		}
		for(int i=j;i>=0;i--)p[i]=0;
		long long l=pow(2,j);
		j-=1;
		for(int i=1;i<=n;i++){
			if((l&a[i])&&pd[i]==1){
				long long k=a[i],o=0;
				while(k!=0){
					p[o]+=k%2;
					k/=2;
					o++;
				}
			}else{
				pd[i]=0;
			}
		}
	}
	return 0;
} 
