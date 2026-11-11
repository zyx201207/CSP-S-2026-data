#include <bits/stdc++.h>
using namespace std;
char x;
string s;
long long id=0,a,ans=0,n,idx=0,q=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>x;
		for(long long i=1;i<=a;i++){
			s+=x;
		}
	}
	id=s.size();
	if(id%2==0) idx=id/2-1;
	else idx=id/2;
	q=id-2;
	for(long long i=0;i<=idx;i++){
		if(s[i]!=s[q-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
