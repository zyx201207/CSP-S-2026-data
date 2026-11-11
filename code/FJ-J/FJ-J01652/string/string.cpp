#include <bits/stdc++.h>
using namespace std;
int a[200005],l=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string c;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int cnt=0;
	for(int i=1;i<=(l+1)/2;i++){
		if(s[i]!=s[n-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}