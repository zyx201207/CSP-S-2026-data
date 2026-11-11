#include <bits/stdc++.h>
using namespace std;
long long n;
string a,h;
long long g[200005];
//bool check(string c){
//	string d;
//	d=c.reverse(c.begin(),c.end());
//	if(d==c) return true;
//	else return false;
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		g[i]=x;
		for(int j=1;j<=x;j++) {
			string b;
			if(j==1){		
				cin>>b;
				h+=b;
			}
			a+=b;
		}
	}
	int cnt=0;
	long long l=0,k=0;
	long long ans=0;
	for(int i=1;i<a.size();i++){
		if(a[i]==a[i-1]) l++;
		else cnt++;
	}
	for(int i=2;i<=n;i++){
		if(g[i]==g[i-1]) l++;
		else k++;
	}
	if(cnt==0) {
		cout<<0;
		return 0;
	}
	
	else if(k==0) {
		cout<<g[1]*n/2;
		return 0
	}
	else{
		for(int i=0;i<a.size();i++){
			a[i]=h[1];
			//if(check(a)) {
			//	ans++;
			//}
		}
	}
	cout<<cnt;
	return 0;
}
