#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],b[N],cnt=0;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l=0,r;
	for(int i=1;i<=n;i++){
		long long q;
		char p;
		cin>>q>>p;
		for(int i=1;i<=q;i++){
			s=s+p;
			
		}
		r+=q;
	}
	r--;
//	cout<<l<<" "<<r<<endl;
	cnt=0;
	while(l<r){
		if(s[l]!=s[r]){
			cnt++;
		}
		
		l++,r--;
	}
	cout<<cnt;
}
