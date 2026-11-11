#include<bits/stdc++.h>
using namespace std;
string s;
char b[100005];
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout); 
	int n,a[100005],len=1,z,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=len;j<=len+a[i]-1;j++){
			s[j]=b[i];
		}
		len+=a[i];
	}
	if(len%2!=0){
		z=len/2+1;
	}
	else{
		z=len/2;
	}
	for(int i=z;i<=len;i++){
		if(s[i]!=s[2*z-i]){
			ans++;
		}
	}
	cout<<ans;
}
