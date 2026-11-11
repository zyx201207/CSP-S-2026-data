#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int u=1;
	for(long long i=1;i<=n;i++){
        long long t;
        char c;
        cin>>t>>c;
        for(long long j=u;j<u+t;j++){
            s[j]=c;
        }
        u+=t;
	}
	int l=1,r=u-1;
	while(l<r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
