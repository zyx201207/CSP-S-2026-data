#include <bits/stdc++.h>
using namespace std;
string s1;
long long n,ans;
bool fun(string x){
	string t=x;
	reverse(x.begin(),x.end());
	if(x==t){
		return 1;
	}
	return 0;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++){
    	int x=1;
    	cin>>x;
    	char s2;
    	cin>>s2;
    	for(int j=1;j<=x;j++){
    		s1+=s2;
		}
	}
	long long len=s1.size();
	for(int i=0;i<len/2;i++){
		if(fun(s1)==1){
			break;
		}
		if(s1[i]==s1[len-1-i]){
			continue;
		}
		else{
			s1[len-1-i]=s1[i];
			ans++;
		}
	}
	cout<<ans;
    return 0;
}
