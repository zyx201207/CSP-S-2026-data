#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b[1000005],c,n,i,d;
string s[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>b[i]>>s[i];
	}
	i=0;
	while(n!=i){
		if(b[i]>=b[n-1]&&s[i]!=s[n-1]){
			c+=b[n-1];
			b[i]=b[i]-b[n-1];
			n--;
		}else if(b[i]<b[n-1]&&s[i]!=s[n-1]){
			c+=b[i];
			b[n-1]=b[n-1]-b[i];
			i++;
		}else if(b[i]>=b[n-1]&&s[i]==s[n-1]){
			b[i]=b[i]-b[n-1];
			n--;
		}else if(b[i]<b[n-1]&&s[i]==s[n-1]){
			b[n-1]=b[n-1]-b[i];
			i++;
		}
	}
	cout<<c;
	return 0;
}
