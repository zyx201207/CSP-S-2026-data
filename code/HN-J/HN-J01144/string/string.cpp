#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],ans;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

