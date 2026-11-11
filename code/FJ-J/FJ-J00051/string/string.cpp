#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long t=n;
	while(t--){
		long long cnt;
		char x;
		cin>>cnt>>x;
		while(cnt--) ss+=x;
	}
	for(int i=0,j=ss.size()-1;i<ss.size()/2 || j>ss.size()/2;i++,j--) if(ss[i]!=ss[j]) ans++;
	cout<<ans;
	return 0;
}
