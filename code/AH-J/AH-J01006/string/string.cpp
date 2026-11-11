#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
string k;
int ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int mm = 0;mm<n;mm++){
		cin>>a[mm];
		cin>>b[mm];
		for(long long i = 0;i<a[mm];i++){
			k+=b[mm];
		}
	}
	for(int i = 0;i<k.length()/2;i++){
		if(k[i] != k[k.length()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
