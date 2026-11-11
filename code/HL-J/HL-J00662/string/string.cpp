#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
int n,a[N],cnt;
string s,t,c,q;
bool b;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>t;
    	cnt+=a[i];
    	while(a[i]--)s+=t;
	}
	
	for(int i=s.size();i>=0;i--){
		c+=s[i];
	}
	for(int i=0;s[i];i++)q+=s[i];
	if(q==s)cout<<0;
	else cout<<cnt/2;
    return 0;
}
