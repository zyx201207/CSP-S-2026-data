#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
string s;
char c[200005];
string asd(string s){
	string x="";
	int len=s.size();
	for(int i=0;i<len;i++){
		x[i]=s[len-1-i];
	}
	return x;
}
string zxc(int x,int len){
	string c="";
	for(int i=x;i<len;i++){
		c+=s[i];
	}
	return c;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	string v=asd(s);
	if(v==s){
		cout<<0;
		return 0;
	}
	int len=s.size();
	string f=zxc(0,len/2);
	string z=zxc(len/2+1,len-1);
	int sum=0;
	int len1=f.size(),len2=z.size();
	for(int i=0;i<max(len1,len2);i++){
		if(f[i]!=z[len2-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
