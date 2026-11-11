#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt,q;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q+=a[i];
		cin>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	for(int i=0;i<=q/2;i++){
		if(s[i] != s[q-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
}
