#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	 freopen("and.out","w",stdout);
	 int n,m,maxs=0,ans=0;
	 cin>>n>>m;
	 int s[n+1];
	 for(int i=1;i<=n;i++){
	 	cin>>s[i];
	 	maxs=max(maxs,s[i]);
	 }
	 if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				int kkk=s[i]&s[j];
				ans=max(ans,kkk);
			}
		}
		cout<<ans;
		return 0;
	}
	 if(m==1){
	 	cout<<maxs;
	 	return 0;
	 }
	 if(m==n){
	 ans=s[1];
	 for(int i=2;i<=n;i++){
	 	ans&=s[i];
	 }
	 cout<<ans;
	 return 0;
	 }
	 if(maxs<4){
	 	
	 	int n3=0,n1=0,n2=0;
	 	for(int i=1;i<=n;i++){
	 		if(s[i]==1)n1++;
	 		if(s[i]==2)n2++;
	 		if(s[i]==3)n3++;
	 		
		 }
		 if(n3>=m){
		 	cout<<3;
		 	return 0;
		 }
		 if(n2>=m){
		 	cout<<2;
		 	return 0;
		 }
		
		 if(n2+n3>=m){
	 			cout<<2;
	 			return 0;
			 }else if(n1+n3>=m){
			 	cout<<1;
			 	return 0;
			 }else{
			 	 if(n1>=m){
		 	cout<<1;
		 	return 0;
		 }
			 	cout<<0;
			 	return 0;
			 }
	 }
	
}

