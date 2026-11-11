#include<bits/stdc++.h>
using namespace std;
int a[1000000001];
int main(){
  //reopen("string.in","r",stdin);
  //reopen("string.out","w",stdout);
   ios::sync_with_stdio(0);
   cin.tie(0);
   string s;
   cin>>s;
   long long n;
   cin>>n;
   int ans=0;
   for(int i=1;i<=n;i++){
	   for(int j=1;j<=i;j++{
		   if(a[i]==a[j]{
			   ans++;
		   }
       }
   }
   cout<<ans;
   return 0;
}
