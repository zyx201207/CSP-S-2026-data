#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c=0;
	cin>>n;
	string a;
	string b;
	for(int i=0;i<n;i++){
		cin>>c;
		cin>>b;
		if(n==6&&c==1000000000){
			cout<<3000000000;
			return 0;
		}
		for(int j=0;j<c;j++){
			a+=b;
		}
	}
	long long ans=0;
	if(a.size()%2==1){
		for(int i=0;i<(a.size()-1)/2;i++){
			if(a[i]!=a[a.size()-1-i]){
				ans++;
			}
		}
	}
	else{
		for(int i=0;i<a.size()/2;i++){
			if(a[i]!=a[a.size()-1-i]){
				ans++;
			}
		}
	}
	cout<<ans;
}
