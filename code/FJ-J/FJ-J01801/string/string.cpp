#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	int f=0;
	long long sum=0;
	for(int i=1;i<=n;i++){
		long long p;
		char c;
		cin>>p>>c;
		if(p>10000000){
			f=1;
		}
		sum+=p;
		if(f==0){
			for(int j=1;j<=p;j++){
				s=s+c;
			}
		}	
	}
	if(f==1){
		cout<<sum/2;
		return 0;
	}
	long long ans=0;
	for(int i=0;i<=sum/2;i++){
		if(s[i]!=s[sum-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
