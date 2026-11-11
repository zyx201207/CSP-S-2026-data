#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
//	freopen("string.out","W",stdout);
    long long n,s[200005],ans=0;string a;
    cin>>n;
    for(int i=1;i<=n;i++){
    	char x;
    	cin>>s[i]>>x;
    	a+=x;
	}
	a=" "+a;
	for(int i=1,j=n;i<=j;){
		if(a[i]!=a[j]&&s[i]&&s[j]){
			if(s[i]<s[j]){
				s[i+1]-=s[j]-s[i];
				ans+=s[j];
			   }else if(s[i]>s[j]){
				s[j-1]-=s[i]-s[j];
				ans+=s[i];
		     	}else{
		     		ans+=s[i];
				 }
				 i++,j--;
		}
		else {
			if(i+1!=j&&s[i]&&s[j]){
				if(s[i]<s[j]){
				s[i+1]-=s[j]-s[i];
				ans+=s[j]-s[i];
			   }else if(s[i]>s[j]){
				s[j-1]-=s[i]-s[j];
				ans+=s[i]-s[j];
		     	}
			}
			    i++,j--;
		}
			
	}                             
	cout<<ans;
	return 0;
} 
