#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	long long a[n+5],ans=0,x=n/2;
	char s[n+5];
	string sum;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		for(int j=0;j<a[i];j++){
			sum+=s[i];
		}
	}for(int i=0;i<n;i++){
		if(sum[i]!=sum[n-1-i]){
			ans++;
		}
	}cout<<ans;
	return 0;
}
