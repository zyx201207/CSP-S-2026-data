#include<bits/stdc++.h>
using namespace std;





int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t;long long ans=0;cin>>n;char c;
	int a[n+5]={0};char s[n+5]={' '};
	for(int i=1;i<=n;i++){
		cin>>t>>c;
		a[i]=t;s[i]=c;
		//cout<<a[i]<<endl; 
	}
	int p=1;n+=1;
	while(p<=n-p){
		
		if(a[p]==a[n-p]){
			if(s[p]==s[n-p])p+=1;
			else {ans+=a[p];p+=1;
			}
		}
		
		else if(a[p]>a[n-p]){
			if(s[p]==s[n-p]){
			a[p]-=a[n-p];
			n-=1;
			}
			else {
			ans+=a[n-p];
			a[p]-=a[n-p];
			n-=1;
			}
		}
		else 
		{
			if(s[p]==s[n-p]){
				a[n-p]-=a[p];p+=1;n+=1;
			} 
			else {ans+=a[p];a[n-p]-=a[p];p+=1;n+=1;
			}
		}
	}
	

		
		
	
	cout<<ans;
	
	
	return 0;}
