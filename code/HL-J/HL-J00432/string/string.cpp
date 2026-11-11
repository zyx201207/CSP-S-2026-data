#include<bits/stdc++.h>
using namespace std;
long long a[200050];
int cnt=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s,c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
		for(int j=0;j<a[i];j++){
			c[cnt]=s[i];
			cnt++;
		}
	}
	for(int i=0;i<cnt/2;i++){
		if(c[i]!=c[cnt-i-1]){
			ans++;
		}
	}
	cout<<ans<<endl;
		return 0;
	}
