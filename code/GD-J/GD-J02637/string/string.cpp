#include<bits/stdc++.h>
using namespace std;
int n,a[200005],Min=0,s[900000000];
long long l=1;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(long long j=l;j<l+a[i];j++){
			s[j]=(int)c;
		}
		l+=a[i];
	}
	l=l-1;
	for(long long i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1]){
			Min=Min+1;
		}
	}
	cout<<Min;
	return 0;
}
