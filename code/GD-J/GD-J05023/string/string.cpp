#include<bits/stdc++.h>
using namespace std;
long long n,cnt1=0,ai,ans=0,cnt2,l=0,r=100,mid;
char s1[1000005],s2[1000005],ci;
int main(){
	
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	while(n>0)
	{
		cin>>ai;
		cin>>ci;
		//cout<<ai<<" "<<ci;
		
		for(int i=1;i<=ai;i++){
			s1[cnt1]=ci;
			//cout<<s1[cnt1];
			
			cnt1++;
			//cout<<cnt1;
		}
		n--;	
	}
	
	r=cnt1-1;
	
//	//cout<<l<<" "<<r;
//	while(l<r){
//		mid=(l+r)/2;
//		if(s1[l]!=s1[r]){
//			l+=1;
//			r-=1;
//			//cout<<l<<" "<<r<<'/n';
//			ans++;
//			//cout<<ans<<" ";
//		}
//		else{
//			l+=1;
//			r+=1;
//		}
//	}
//	cout<<ans;

	for(int i=cnt1-1;i>=0;i--){
		s2[cnt2]=s1[i];
		//cout<<s2[cnt2];
		cnt2++;
	}
	for(int i=0;i<cnt1;i++){
		if(s1[i]!=s2[i]){
			ans++;
			//cout<<ans<<" ";
		}
	}
	cout<<ans/2;


	return 0;
} 
