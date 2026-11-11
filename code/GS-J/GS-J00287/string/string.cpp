#include<bits/stdc++.h>
using namespace std;
long long a,q,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		long long x;
		char y;
		cin>>x>>y;
		while(x--){
			s+=y;
			q++;
		}
	}
		for(int i=0;i<q/2;i++){
			char m=s[i],n=s[q-i-1];
			if(m!=n){
				ans++;
			}
		}
		cout<<ans;
	return 0;
}
