#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005]; 
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(long long i = 1;i <= n;i++){
		cin>>a[i]>>c[i];
		for(int j = 1;j <= a[i];j++){
			s+=c[i];
		}
	 } 
	for(long long i = 1;i <= n;i++){
		if(s[i]==s[n-i+1]){
			continue;
		}else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
