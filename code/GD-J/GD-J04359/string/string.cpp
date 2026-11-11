#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,b;
	cin >> n;
	string s,z;
	if(n==1){cout << 0;return 0;}
	else if(n==2){
		cin >> a >> s >> b >> z;
		if(s!=z){
			cout << min(a,b);
			return 0;
		}
		else{cout << 0;return 0;}
	}
	else{
        for(long long i=0;i<n;i++){
        	cin >> a >> s;
        	for(long long j=0;j<a;j++) z+=s;
		}
		long long len=z.size();
		if(len%2==0){
			string p,q;
			for(long long i=0;i<len/2;i++) p+=z[i];
			for(long long i=len/2;i<len;i++) q+=z[i];
			//cout << p << " " << q; 
			long long cnt=0,l=len/2;
			for(long long i=0;i<l;i++){
				if(p[i]!=q[l-i-1]) cnt++;
			}
			cout << cnt;
		}
		else{
			string p,q;
			for(long long i=0;i<len/2;i++) p+=z[i];
			for(long long i=len/2+1;i<len;i++) q+=z[i];
			//cout << p << " " << q; 
			long long cnt=0,l=len/2;
			for(long long i=0;i<l;i++){
				if(p[i]!=q[l-i-1]) cnt++;
			}
			cout << cnt;
		}
	}
	return 0;
}
