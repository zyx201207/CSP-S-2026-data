#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long b[1000000];
long long c[1000000];
int d=10;
int y;
int main(){ 
	freopen("in.and","r",stdin);
	freopen("out.and","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=m;j++){
			if(a[i]>b[j]){
				b[j]=a[i];
			}
		}
	}
	int sum;
	int ans;
	for(int i=1;i<=m;i++){
		int s=b[i];
		while(s>0){
			c[i]=s%2;
			c[i]*=10;
			s/=2;	
		}
		while(c[i]>0){
			if(ans%d==c[i]){
				sum+=c[i];
				sum*=10;
				c[i]/=10;
				y++;
			}	
		}
		
		if(i=1){
			int ans=c[i];
		}
		else{
			ans=sum;
			sum=0;
		}	
	}
	int ujh;
	for(int i=1;i<=y;i++){
		ujh+=(sum%10)*2^y;
		sum/=10;
	}
	
	return 0;
}
