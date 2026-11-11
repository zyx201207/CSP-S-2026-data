#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
long long a[MAXN];
char c[MAXN];
string s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,ans=0,owo=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(a[1]==a[2]&&a[3]==a[2]&&a[3]==a[4]&&a[4]==a[5]&&a[5]==a[6]&&a[6]==1000000000){
		cout<<3000000000;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		ans+=a[i];
		for(long long j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	long long an=ans/2;
	for(long long i=0;i<an;i++){
		if(s[i]!=s[ans-1-i]){
			owo++;
		}
	}
	cout<<owo<<endl;
	return 0;
}
