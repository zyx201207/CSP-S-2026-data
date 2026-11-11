#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
string s;
long long l;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]){
			cnt++;
			
		}
	}
	
	
	cout<<cnt;
	return 0;
}
