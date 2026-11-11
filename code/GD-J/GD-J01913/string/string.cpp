#include<bits/stdc++.h>
using namespace std;
long long n,a[400005],cnt=0;
string ss,ns;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char s;
		cin>>a[i]>>s;
		for(int j=1;j<=a[i];j++){
			ss+=s;
		}
	}
	for(int i=0;i<ss.size()/2+1;i++){
		if(ss[i]!=ss[ss.size()-1-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
