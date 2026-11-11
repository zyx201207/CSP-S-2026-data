#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long sum=0,ans=0;
string s,s1,s2;
char ch;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		s=s+(char)c[i]*a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	
	if(sum%2==0){
		for(int i=0;i<sum/2;i++){
			if(s[i]!=s[sum-i-1]){
				ans++;
			}
		}
	}
	else{
		for(int i=0;i<sum/2;i++){
			if(s[i]!=s[sum-i-1]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
