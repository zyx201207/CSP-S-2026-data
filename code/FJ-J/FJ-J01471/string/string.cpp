#include<bits/stdc++.h>
#include<string>
using namespace std;
string s[20000001],ci[20000001],u[20000001];
int a[20000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,m=0,l=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>ci[i];
		m+=a[i];
		}
	for(int i=0;i<n;i++){
		for(int j=a[i];j>0;j--){
		     s[l]=ci[i];
		     if(l<m){l++;}
		   }
		}
		l=0;
		for(int i=0;i<m/2;i++){
			u[i]=s[i];
		}	
	    for(int j=m-1;j>m/2;j--){
	    	if(u[l]!=s[j]){
	    	  ans++;
			}
			if(l<m/2){
			   l++;	
			}
		} 
	cout<<ans<<"\n";
	return 0;
} 
