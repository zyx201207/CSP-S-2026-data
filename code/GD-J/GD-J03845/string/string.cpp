#include<bits/stdc++.h>
using namespace std;
long long n,a[210000],cnt,sum;
char c[210000];
string s,b;
int main(){
	//freopn("string.in","r",stdin);
	//freopn("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	b=s;
	reverse(s.begin(),s.end());
	if(b==s){
		cout<<0;
		return 0;
	}
	for(int i=0;i<=sum/2;i++){
		if(b[i]!=s[i]) cnt++;
	}
	cout<<cnt;
}
