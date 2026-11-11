#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],len,ans;
char c[20005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	len=s.size();
	for(long long i=len-1;i>=len/2;i--){
		if(s[i]!=s[len-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
