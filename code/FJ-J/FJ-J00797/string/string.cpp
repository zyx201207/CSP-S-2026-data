#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a[111111],n;
	char c[111111];
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int p=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n-i+1]){
			p=1;
			break;
		}
	}
		if(p==0){
			long long maxn=0;
			for(int i=1;i<=n/2;i++){
				maxn+=a[i];
			}
			cout<<maxn;
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}	
		}
		
	int v=0;
	for(int i=0;i<s.size();i++){
		for(int j=s.size()-1;j>=0;j--){
			if(s[i]!=s[j]){
				v=1;
				break;
			}
		}
		if(v==1){
			break;
		}
	}
	if(v==0){
		cout<<0;
		return 0; 
	}
	
	if(p==0){
		
	}
	if(n%2!=0){
		int sum=0;
		for(int i=0;i<s.size()/2;i++){
				if(s[i]!=s[s.size()-i]){
					sum++;
			}
		}
		cout<<sum;
	}
	else{
		int ans=0;
		for(int i=0;i<s.size()/2;i++){
				if(s[i]!=s[s.size()-i]){
					ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 
