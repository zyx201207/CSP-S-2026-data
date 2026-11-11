#include<bits/stdc++.h>
using namespace std;
int n,a[200005],len,ans;
char c[200005];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0,j=len-1;i<len/2&&j>=len/2;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}
