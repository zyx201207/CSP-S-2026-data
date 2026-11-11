#include <bits/stdc++.h>
using namespace std;
string s;
long long a,n;
long long m=0;
long long ans=0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(long long j=m;j<m+a;j++){
			s[j] = c;
		}
		m+=a;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(m%2==0){
		ans=0;
		for(long long i=0;i<m/2;i++){
			for(long long j = m-1;j>=m/2;j--){
				if(s[i] != s[j]){
					ans+=1;
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else if(m%2!=0){
		ans=0;
		for(long long i=0;i<m/2;i++){
			for(long long j = m-1;j>m/2;j--){
				if(s[i] != s[j]){
					ans+=1;
					break;
				}
			}
		}
		cout<<ans;
		return 0;
	}
} 
