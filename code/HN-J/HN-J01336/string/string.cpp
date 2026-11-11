#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],len=0;
long long ans=0;
string c[N];
string s1[N],s2[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s1[len]=c[i];
			s2[len]=c[i];
			len++;
		} 
	}
	for(int i=0;i<len/2+1;i++){
		if(s1[i]!=s2[len-i-1]){
			s1[i]=s2[len-i-1];
			s2[i]=s2[len-i-1];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
