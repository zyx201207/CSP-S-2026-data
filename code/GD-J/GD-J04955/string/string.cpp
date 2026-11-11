#include<bits/stdc++.h> 
using namespace std;
long long a[20000005];
char b[20000005],x[20000005];//aÊý×Öb×ÖÄ¸ 
int main (){
	long long n,flag=1,sum=0,ans=0,ii=1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	for(long long i=2;i<=n;i++){
		if(b[i]==b[i-1]){
			continue;
		}
		else{
			flag=0;
			break;
		}
	}
	if(flag==1){
		cout<<0;
		return 0;
	}
	//ÅÐ¶Ï 
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			x[ii]=b[i];
			ii++;
		}
	}
	for(long long i=1;i<=sum/2;i++){
		if(x[i]==x[sum+1-i]){
			continue;
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
