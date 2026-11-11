//GZ-J00206 杨俊毅 遵义市南白初级中学 
#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
long long a[200005];
string s="";
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  	cin>>n;
  	for(long long i=1;i<=n;i++){
  		char c;
  		cin>>a[i]>>c;
  	    s.insert(s.size(),a[i],c);
  	}
	  for(long long i=0,j=s.size()-1; ;i++,j--){
	  	if(s.size()%2==0){
	  		if(j-i==1) break;
		  }else if(j==i) break;
	  	if(s[i]!=s[j]){
	  		ans++;
		  }
	  }
	  cout<<ans;
	return 0;
}

