#include<bits/stdc++.h>
using namespace std;
long long a[200005],h=0;
string b[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		h+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	h/=2;
	for(int i=1;i!=n-i+1&&i<=n;i++){
		if(s[i]==s[n-i+1]){
			h--;
		}
	}
	cout<<h;
	return 0;
}
