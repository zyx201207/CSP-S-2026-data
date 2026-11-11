#include<bits/stdc++.h>
using namespace std;
char l[1000000000],n[100000000];
long long a[1000000000],t,ans=0,sum=0;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>t;
	for(long long i=1;i<=t;i++){
		cin>>a[i]>>n[i];
		for(long long j=sum+1;j<=sum+a[i];j++){
			l[j]=n[i];
		}
		sum+=a[i];
	}
	for(long long i=1;i<=sum/2;i++){
		if(l[i]!=l[sum-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
