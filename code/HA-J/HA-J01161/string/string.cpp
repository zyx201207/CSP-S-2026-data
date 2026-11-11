#include <bits\stdc++.h>
using namespace std;
long long n,a[200005],cnt,sum,ls;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a1;
		char c1;
		cin>>a1>>c1;
		ls+=a1;
		if(c[cnt]==c1){
			a[cnt]+=a1;
		}else{
			a[++cnt]=a1;
			c[cnt]=c1;
		}
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	if(cnt==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	for(long long i=1;i<=cnt;i++){
		string s1="";
		for(int j=1;j<=a[i];j++){
			s1=s1+c[i];
		}
		s=s+s1;
	}
	for(long long i=1;i<=ls/2;i++){
		if(s[i]!=a[ls-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

