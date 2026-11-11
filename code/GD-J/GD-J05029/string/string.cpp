#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n;
int a[N];
char c[N];
string s="";
long long minn;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
		for(int j=0;j<a[i];j++) s+=c[i];
	}
	int len=(int)s.size();
	for(int i=0;i<(len+1)/2;i++) if(s[i]!=s[len-i-1]) minn++;
	cout<<minn;
	return 0;
}
