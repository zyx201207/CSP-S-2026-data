#include<bits/stdc++.h>
using namespace std;
long long n,x,len,ans;
char ch;
string st,a,b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>ch;
		for(int j=1;j<=x;j++){
			st+=ch;
		}
	}
	len=st.size();
	st=' '+st;
	if(len%2==0){
		for(int i=1;i<=len/2;i++){
			a+=st[i];
		}
		for(int i=len/2+1;i<=len;i++){
			b+=st[i];
		}
	}
	else{
		for(int i=1;i<=len/2;i++){
			a+=st[i];
		}
		for(int i=len/2+2;i<=len;i++){
			b+=st[i];
		}
	}
	for(int i=0;i<b.size();i++){
		c+=b[b.size()-1-i];
	}
	len=a.size();
	a=' '+a;
	c=' '+c;
	for(int i=1;i<=len;i++){
		if(a[i]!=c[i]) ans++;
	}
	cout<<ans;
	return 0;
}
