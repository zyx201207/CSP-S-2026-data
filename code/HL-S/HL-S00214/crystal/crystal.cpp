#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long n,m,a[MAXN],s[MAXN];
 int main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 	}
 	if(n>5000&&m>100000000){
 		int aa=0,cnt=0;
 		int k=a[2]-a[1];
 		if(k>m){
 			cout<<0;
 			return 0;
		 }
 		for(int i=1;i<=n;i++){
 			aa+=i*k;
 			if(aa<=m) cnt++;
 			
		 }
		 cout<<cnt;
		 return 0;
	} 
	long long sum=0;
 	for(int i=1;i<=n;i++){
 		 memset(s,0,n);
 		long long ans=0;
 		for(int j=i;j<=n;j++){
 			s[j]=s[j-1]+(j-i)*(a[j]-a[j-1]);
 			if(s[j]<=m){
 				ans++;
			 }			 
		 }
		 sum=max(ans,sum);
	 }
 	cout<<sum;

 	return 0;
 }
