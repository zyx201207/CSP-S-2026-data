#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
long long n,a[N],ans;
char c[N];
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0,j=s.size()-1;i<s.size(),j>=0;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
