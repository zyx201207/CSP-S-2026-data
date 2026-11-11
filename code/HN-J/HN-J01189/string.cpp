#include <bits/stdc++.h>
#include <string>
using namespace std;
const int MAXN=200005;
long long a[MAXN];
char c[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sum=0;
	string s="";
	for(int i=1;i,=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		s+=c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0;
			return 0;
		}else{
			cout<<min(a[1],a[2]);
			return 0;
		}
	}
	long long cnt1=0;
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum-i]){
			cnt1++;
		}
	}
	cout<<cnt1;
	return 0;
}
