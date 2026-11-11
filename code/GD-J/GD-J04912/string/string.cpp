#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string a;
	for(int i=1;i<=n;i++){
		long long cnt;
		string s;
		cin>>cnt>>s;
		for(int i=1;i<=cnt;i++){
			a+=s;
		}
	}
	long long m=a.size();
	long long cnt=0;
	for(int i=0;i<=m/2;i++){
		if(a[m-i-1]!=a[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
