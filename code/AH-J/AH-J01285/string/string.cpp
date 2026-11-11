#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
   int n;
   cin>>n;
   string s="";
   while(n--){
	   ll l;
	   char ch;
	   cin>>l>>ch;
	   while(l--){
		   s+=ch;
	   }
   }
 //  cout<<s<<'\n';
   string s2=s;
   reverse(s.begin(),s.end());
   if(s2==s){
	   cout<<0<<'\n'; 
	   return 0;
   }
   
   ll l2=s2.size();
   ll l1=0,r=l2-1;
   ll ans=0;
   while(l1<r){
	   ans+=(s2[l1]!=s2[r]);
	   l1++,r--;
   }
   cout<<ans;
   return 0;
}
