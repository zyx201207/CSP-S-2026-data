#include<bits/stdc++.h>
using namespace std;
long long a[500005],d[500005],p;	
long long n,m,r=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=a[(n+1)/2];
   	for(long long j=1;j<=n;j++){
	    d[j]=abs(l-a[j]);
	   }
	for(int j=1;j<=n;j++){
		if(p+d[j]<=m){
			p+=d[j];r++;
		}
		else continue;
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
