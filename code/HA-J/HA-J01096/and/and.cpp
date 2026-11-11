#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100100];
bool b[31];
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ma=pow(2,30);
	memset(b,1,sizeof(b));
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];
	sort(a,a+n-1);
	for(long long i=n-1;i>n-m;i--){
		long long x=ma;
		long long k=0;
		while(x>=1){
			if(a[i]>=x){
				b[k]=1&&b[k];
				a[i]-=x;
			}else b[k]=0&&b[k];
			x/=2;
			k++;
		}	
	}
	for(int i=0;i<=30;i++) 
		if(b[i]==1) ans+=pow(2,30-i);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
