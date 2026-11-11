#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long cnt,q;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	q=s.length();
	for(long long i=0;i<ceil(q*1.0/2);i++){
		if(s[i]!=s[q-1-i]) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
