//string

#define LL long long
#include <bits/stdc++.h>
using namespace std;

LL n;
LL ans; 
string s;
string s2; //s的前半部分倒序存储后 
//暴力解法：用s2与s的后半部分比较，有不同的字符就换成相同的 
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++) {
		int a;
		char c;
		cin>>a;
		cin>>c;
		string s1(a,c);
		s+=s1;
	}
	//cout<<s<<endl;
	LL len=s.size();
	//cout<<len<<endl;
	s2.resize(len/2);
	for(int i=0;i<len/2;i++) {
		s2[len/2-1-i]=s[i];
	}
	//cout<<s2<<endl;
	int mid=(len&1?len/2+1:len/2);
	//cout<<mid<<endl;
	for(int i=0;i<s2.size();i++) {
		if(s2[i]!=s[mid+i]) ans++;
	}
	
	cout<<ans<<endl;
	return 0;
}
/*LL a[200010];
char c[200010];
LL len;

//最少修改次数 
LL solve() {
	LL res=0;
	for(int i=0;i<n/2;i++) {
		if(a[i]!=a[n-1-i]&&c[i]!=c[n-1-i]) res+=max(a[i],a[n-1-i]);
		else if(a[i]==a[n-1-i]&&c[i]!=c[n-1-i]) res+=a[i];
	}
	return res;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		cin>>c[i];
		len+=a[i];
	}
	cout<<solve()<<endl;
	return 0;
}*/
