#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,s;
char c;
string t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			t+=c;
		}
	}
	for(int i=0;i<t.size();i++){
		if(t[i]!=t[t.size()-i-1]){
			s++;
		}
	}
	cout<<s/2;
	return 0;
}
