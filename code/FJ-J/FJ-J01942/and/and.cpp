#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int n,m;
bool b[200010][40];
int c[40];
int d[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		long long x=a[i],j=0;
		while(x){
			b[i][j]=x%2;
			x/=2;j++;
		}
	}
	for(int i=31;i>=0;i--){
		for(int j=0;j<n;j++){
			if(d[j]==0){
				if(b[j][i]==0){
					d[j]=2;
				}else{
					c[i]++;
				}
			}
		}
		if(c[i]>=m){
			c[i]=1;
		}else{
			c[i]=0;
		}
		for(int j=0;j<n;j++){
			if(c[i]==0&&d[j]==2){
				d[j]=0;
			}if(c[i]==1&&d[j]==2){
				d[j]=1;
			}
		}
	}
	long long x=1,ans=0;
	for(int i=0;i<=31;i++){
		ans+=x*c[i];
		x*=2;
	}
	cout<<ans;
}
