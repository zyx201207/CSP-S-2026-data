#include<bits/stdc++.h>
using namespace std;
bool hui(string x){
    for(int i=0;i<=x.size()/2;i++){
        if(x[i]!=x[x.size()-i])return false;
    }
    return true;
}
int main()
{
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c,ans=0;
	char a;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>c>>a;
        for(int i=1;i<=c;i++)s+=a;
	}
	if(!hui(s)){
        cout<<0;
        return 0;
	}
	int len=s.size();
	for(int i=0;i<=len/2;i++){
        if(s[i]!=s[len-i])ans++;
	}
	cout<<ans;
}
