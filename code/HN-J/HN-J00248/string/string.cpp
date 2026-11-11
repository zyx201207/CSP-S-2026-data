#include<bits/stdc++.h>
using namespace std;
const int N = 50005;
int ans = 0;
int n;
int a[N],c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("strinng.out","w",stdout);
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0<<endl;
			return 0;
		}else{
			ans = a[1]+a[2];
			ans /= 2;
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[k] = c[i];
			k++;
		}
	}
	int len=0;
	for(int i=1;i<=n;i++){
		len+=a[i];
	}
	for(int i=1;i<=len;i++){
		if(len%2!=0){
			ans = len/2;
		}
		if(len%2==0&&s[len]-s[1]==0){
			ans = len/2;
		}
		if(s[i]==s[len+1-i]){
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
