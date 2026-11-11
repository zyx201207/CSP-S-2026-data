#include<bits/stdc++.h>
#define unsigned int long long
using namespace std;
signed main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
		 int cnt=0;
	   int n;cin>>n;
	   string s;
	   for(int i=1;i<=n;i++){
	   	int x;cin>>x;
	   	char a;cin>>a;
	   	while(x--){
	   		s+=a;
		   }
	   }
	   if(n==1){
	   	cout<<0;
	   	return 0;
	   }
	   int l,r;
	   l=0;r=s.size()-1;
	   while(l<r){
	   	if(s[l]!=s[r]){
	   		cnt++;
	   		s[r]=s[l];
		   }
		   l++;
		   r--;
	   }
	   cout<<cnt;
	   return 0;
}
