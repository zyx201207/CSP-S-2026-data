#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	
	long long a[200005];
	for(long long i=0,ans=0;i<n;i++){
		  scanf("%lld",&a[i]);
		 char c;
		 cin>>c;
		for(long long j=ans;j<ans+a[i];j++){
			s[j]=c;
		}
		ans+=a[i];
}long long sum=0;
long long num=0;
for(long long i=0;i<n;i++){
	num+=a[i];
}

     for(long long i=0;i<num/2;i++){
     	if(s[i]!=s[num-i-1]){
     		sum++;
		 }
	 }cout<<sum;
     return 0;
}
