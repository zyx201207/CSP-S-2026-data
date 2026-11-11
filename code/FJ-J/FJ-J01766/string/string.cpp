#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	long long n,a[200005];
	long long sum=0;
	cin>>n;
	if(n==1){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]&&s[i]!=s[i+1]){
			if(a[i]>a[i+1]){
				sum=(a[i]-a[i+1])*2;
			}
			else{
				sum=(a[i+1]-a[i])*2;
			}
		}
		if(a[i]!=a[i+1]&&s[i]==s[i+1]){
			sum+=0;
		}
		if(a[i]==a[i+1]&&s[i]!=s[i+1]){
			sum+=a[i]*(n/2);
		}
	}
	cout<<sum;
	return 0;
}
