#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],ans=0;
char c[100005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++){
		 cin>>a[i]>>c[i];	
		 for(long long j=0; j<a[i]; j++) s+=c[i];
	}
	long long l=s.size();
	for(long long i=0,j=l-1; i<l/2,j>=l/2; i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
