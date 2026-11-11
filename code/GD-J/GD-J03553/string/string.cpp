#include<bits/stdc++.h>
using namespace std;
long long n,a,s,t;
string c;
vector<string> v;
int main(){
//	freopen("string3.in","r",stdin);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		t+=a;
		for(long long j=1;j<=a;j++){
			v.push_back(c);
			cout<<c;
		}
	}
	for(long long i=t/2;i>=0;i--){
		for(long long j=0;j<=t/2;j++){		
			if(v[i]!=v[j]){
				s++;
			}
		}
	}
		
	cout<<s;
	return 0;
}
