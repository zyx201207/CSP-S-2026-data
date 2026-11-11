#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],m,l,ans;
char c[200005],sa;
string s;
bool same=1,len=1;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i==1){
			sa=c[i];
			l=a[i];
		}
		if(sa!=c[i])
			same=0;
		if(l!=a[i])
			len=0;
		m+=a[i];
	}
	if(same){
		cout<<0;
		return 0;
	}
	if(len){
		for(int i=1;i<=n;i++)
			s+=c[i];
		m=n;
	}else{
		for(int i=1;i<=n;i++){
			while(a[i]--)
				s+=c[i];
		}
	}
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-1-i])
			ans++;
	}
	if(len)
		cout<<ans*l;
	else
		cout<<ans;
	return 0;
}
