#include<bits/stdc++.h>
using namespace std;
long long n,k,l=0,ans=0;
char a;
char aa[100000005];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
	cin>>k;
	cin>>a;
	for(long long j=1;j<=k;j++){
		l++;
		aa[l]=a;
	}
	
	
	}for(long long j=1;j<=l;j++){
		
		//cout<<aa[j]<<endl;
	}for(long long j=1;j<=l/2;j++){
		if(aa[j]!=aa[l+1-j]){
			ans++;
		} 
		
	}
	
	cout<<ans;
	
	
	
	
	
	
	
	
	
}
