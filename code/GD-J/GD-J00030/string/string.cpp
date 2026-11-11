#include<bits/stdc++.h>
using namespace std;
long long q;
string a;
long long ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		cin>>q;
		char b;
		cin>>b;
		while(q--){
			a+=b; 
		}
	}
	long long le=a.size();
	for(long long i=0;i<le/2;i++){
		if(a[i]!=a[le-i-1]){
			ans++;
		}
	}
	cout<<ans;
}
