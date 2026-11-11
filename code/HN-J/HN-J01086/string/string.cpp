#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200200];
char c[200200];
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for (int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for (int i=0,j=s.length()-1;i<=j;i++,j--){
		if (s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}

