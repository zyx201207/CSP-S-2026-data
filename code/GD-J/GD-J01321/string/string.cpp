#include<bits/stdc++.h>
using namespace std;

int main(){
	
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	long long n,sum=0,ans=0;
	char c[10000000]={};
	cin>>n;
	int cnt=1;
for(int i=1;i<=n;i++){
	int a;
	char b;
	cin>>a>>b;
	for(int j=cnt;j<=a+cnt-1;j++){
		c[j]=b;
	}
	cnt+=a;
	sum+=a;
	
}
long long sum1=ceil(sum*1.0/2);
for(int i=1;i<=sum1;i++){
	if(c[i]!=c[sum-i+1])ans++;

}
cout <<ans;
return 0;
}




//aaabb
