#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	
 	int n,a;
 	char c;
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>a>>c;
	 }
	 int l=0;
	 for(int i=n;i>=n-1;i--){
	 	l+=i;
	 
	 }
	 if(l==a)cout<<"0";//specail

	 else {
	 	
	 	long long ans=0;
	
		 
	 	for(int j=l;j>=l;j--){
	 		
	 		ans+=j-(a+1)-1;
	 		cout<<ans<<"\n";
	 		if(ans>1000000000){
	 			ans+=j+(a-1)+1;
			 }
		 }
	 }
	 
	 return 0;
}
