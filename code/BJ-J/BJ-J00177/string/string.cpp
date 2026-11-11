#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
struct c{
	long long b;
	char ch;
};
c a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n==1){
		cout << 0;
		return 0;
	}
	for(int i=1;i<=n;i++){
	    cin >> a[i].b >> a[i].ch;
	    m+=a[i].b;
	    for(int j=1;j<=a[i].b;j++)
			s+=a[i].ch;
	}
	//cout << s << endl;
	for(int i=0;i<=floor(m/2.0);i++){
		string s1=s;
		reverse(s1.begin(),s1.end());
		if(s1==s){
			cout << i;
			return 0;
		}
		s[i]=s[m-i-1];
		//cout << s<< ' ' << s1 << endl;
	}
	return 0;
}