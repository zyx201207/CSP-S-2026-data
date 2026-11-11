#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[500005],sum,cur[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)	
	{
		cin>>a[i];
	}
	//sort(a,a+n);
	for(long long i=1;i<n;i++){
		cur[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<n;i++){
		sum+=cur[i]*i;
		if(m==sum){
			ans=i+1;
			break;
		}
		if(m<sum){
			ans=i;
			break;
		}
	}
	
	
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
