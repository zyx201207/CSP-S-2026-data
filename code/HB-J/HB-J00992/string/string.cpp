#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long num;
	char c;
}a[200005];
char s[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		for(long long j=0;j<a[i].num;j++){
			s[cnt]=a[i].c;
			cnt++;
		}
	}
	for(long long i=0;i<cnt/2;i++){
		if(s[i]!=s[cnt-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
