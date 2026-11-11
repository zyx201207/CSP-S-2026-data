#include<bits/stdc++.h>
using namespace std;
int n;
int a[201010];
char c[201010];
long long sum,tot;
string str;
int len;
int ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			str=str+c[i];
		}
	}
	len=str.length();
	str=' '+str; 
	for(int i=1;i<=len/2;i++){
		if(str[i]!=str[len-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
//aabbc
//aaaaaabbbbbbccc
