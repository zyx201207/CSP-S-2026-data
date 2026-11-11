#include<bits/stdc++.h> 
using namespace std;
long long n;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	 cin>>n;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i]>>c[i];
	 }
	 int ans=0;
	 int p=0,cnt=0;
	 for(int i=1;i<=n/2;i++){
	 	for(int j=i+1;j<=n;j++){
	 		if(c[i]==c[j]){
	 			ans++;
			 }else{
			 	 p=i;
			 }
		 }
	 }
	 if(ans==n){
	 	cout<<0;
	 }else{
	 	for(int k=1;k<=p;k++){
	 		cnt+=a[k];
		 }
		 cout<<cnt;
	 }
	return 0;
}
