#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		char c;
		cin>>num>>c;
		string b;
		for(int i=1;i<=num;i++){
			b+=c;
		}
		a+=b;
	}
	int ans=0;
	n=(a.size()+1)/2-1;
	for(int i=0;i<=n;i++){
		if(a[i]!=a[a.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
} 
