#include<bits/stdc++.h>
using namespace std;
const int ml=2*1e5+5;
struct data{
	int num;char c;
}in;
long long n,ans;
vector<data> a(ml);
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		for(long long j=1;j<=a[i].num;j++)s+=a[i].c;
	}
	for(long long i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
}

