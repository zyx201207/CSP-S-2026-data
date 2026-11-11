#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef unsigned long long ull;
int n,d,a[200005];
ull len;
char c[200005]; 
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],d=__gcd(d,a[i]);
	//cout<<d<<endl;
	for(int i=1;i<=n;i++){
		s.insert(len,a[i]/d,c[i]);
		len+=a[i]/d;
	}
	string t1=s.substr(0,(len+1)/2),t2=s.substr(len/2,len-len/2+1);
	reverse(t2.begin(),t2.end());
//	cout<<s<<endl<<len<<endl<<t1<<" "<<t2<<endl; 
	if(t1==t2)cout<<0<<endl;
	else{
		ull res=0;
		for(ull i=0;i<(len+1)/2;i++)if(t1[i]!=t2[i])res++;
//		cout<<endl;
		cout<<res*1ull*d<<endl;
	}//不会写J T2 正解写暴力的都来了，空悲切。 
	return 0;
}
