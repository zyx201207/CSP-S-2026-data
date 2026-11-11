//GZ-J00619 北京师范大学贵阳附属中学 杨然
#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1001000;
long long n,m = -1,ans,l,c;
string sum;
char s[maxn];
bool ishw(string a){
	string s = a;
	int l = s.size(),c = 0;
	for(int i = l - 1;i>=0;i--)if(s[i]!=a[c++])return false;
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld ",&l);
	    cin>>s[i];
	    char x = s[i];
	    while(l--){
	    	sum += x;
		}
		if(l > m)m = l;
		if(a[i] = a[i-1])m+=l;
	}
	if(ishw(sum)){
		cout<<"0";
		return 0;	
	}
	else cout<<m;
	return 0;
}
