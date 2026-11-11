#include<bits/stdc++.h>
using namespace std;
string s,c;
int cnt,n;
long long len;
char a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<=n-1;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
		len+=a[i];
	}
	for(int i=0;i<=ceil(len*1.0/2);i++){
		if(s[i] != s[len - i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
