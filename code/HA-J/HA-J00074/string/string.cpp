#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
long long ans;
char a;
long long num[200005];
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  cin>>n;
  for(int i=0;i<n;i++){
  	cin>>m>>a;
  	s+=a;
  	num[i]=m;
  }
  //for(int i=0;i<=s.size();i++)cout<<s[i];
  long long l=0,r=s.size()-1;
 
   while(l<=r){//cout<<s[l]<<s[r]<<'\n';
   
   if(s[l]==s[r]) {
  		if(num[r]>num[l]){
  			num[r]-=num[l];
  			l++;
  		}
  		else if(num[l]==num[r]){
  			l++;
  		    r--;
  		}
  		else {
  			num[l]-=num[r];
  			r--;
  		}
  	}
	   else if(s[l]!=s[r]){
  		if(num[l]>num[r]){
  			num[l]-=num[r];
  			ans+=num[r];
  			r--;
  		}
  		else if(num[l]<num[r]){
  			num[r]-=num[l];
  			ans+=num[l];
  			l++;
  		}
  		else {
  			ans+=num[r];
  			l++;r--;
  			
  		}
  	}
  
  }cout<<ans;
  return 0;
}

