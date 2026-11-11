#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],len=0,ans=0;
char c[200005];
string s="1";
bool f=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	for(int i=1,j=n;i<j;i++,j--){
		if(a[i]==a[j]&&c[i]!=c[j]){
			for(int k=2;k<=n/2;k++){
				if(a[k]!=a[k-1]){
					f=0;
					break;
				}
			}
			for(int k=n/2+2;k<=n;k++){
				if(a[k]!=a[k-1]){
					f=0;
					break;
				}
			}
			if(f)cout<<len/2;
		}
		if(a[i]=a[j]&&c[i]==c[j]){
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=1,j=len;i<j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
