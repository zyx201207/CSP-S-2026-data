#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n;
	long long int a[100005];
	char c[100005];
	
	cin>>n;
	for(long long int i=1;i<=n;i++) cin>>a[i]>>c[i];
	
	int ans=0;
	for(long long int i=1;i<=n-1;i++) if(c[i]==c[i+1]) ans++;
	if(ans==n-1){
		cout<<0;
		return 0;
	}
	
	string s="";
	for(long long int i=1;i<=n;i++){
		for(long long int j=1;j<=a[i];j++) 
		{
			s+=c[i];
		}
	}
	long long int cnt=0;
	long long int l=s.size();
	if(l%2!=0){
		char n[10005],m1[10005];
		for(long long int i=0;i<=(l-1)/2-1;i++){
			n[i]=s[i];
		}
		long long int h=0;
		for(long long int i=l-1;i>=(l+1)/2;i--){
			m1[h]=s[i];
			h++;
		}	
		for(long long int i=0;i<=h-1;i++){
			if(n[i]!=m1[i]) cnt++; 
		}
	}else{
		char n[10005],m1[10005];
		for(long long int i=0;i<=l/2-1;i++){
			n[i]=s[i];
		}
		long long int h=0;
		for(long long int i=l-1;i>=l/2;i--){
			m1[h]=s[i];
			h++;
		}
		for(long long int i=0;i<=h-1;i++){
			if(n[i]!=m1[i]) cnt++; 
		}
	}
	cout<<cnt;
} 
