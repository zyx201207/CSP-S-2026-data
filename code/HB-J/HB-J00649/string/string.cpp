#include <bits/stdc++.h>
using namespace std;
int n,sum=0;
long long ans=0;
long long s[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		sum+=a;
		for(int j=1;j<=a;j++){
			s[sum-a+j]=(b-'a');
			
		}
	}
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum+1-i]){
			ans++;
			
		}
	}
	cout<<ans;
		
	

}

