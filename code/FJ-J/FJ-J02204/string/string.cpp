#include<bits/stdc++.h>
using namespace std;
string S[100000999];
long long sum=0,ans=0;
int n,a;
string c;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			S[sum]=c;
			sum++;
		}
	}
	if(sum%2==1){
		sum--;
		for(int i=0;i<(sum+1)/2;i++){
			if(S[i]!=S[sum-i]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=0;i<=2;i++){
		if(S[i]!=S[sum-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
