#include <bits/stdc++.h>
using namespace std;
bool huiwen(string kk){
	long long l=kk.size();
	for(long long h=0;h<=l/2;h++){
		long long m=l-1-h;
		if(kk[h]!=kk[m]){
			return false;
		}
	}
	return true;
}
long long k[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	long long n;
	cin >> n;
	string s=""; 
	long long ma=0,mm=0;
	for(long long i=1;i<=n;i++){
		long long h;
		char a;
		cin >> h >> a;
		mm+=h;
		for(long long j=1;j<=h;j++){
			s+=a;
		}
		int ww=a-'a'+1;
		k[ww]+=h;
		ma=max(ma,k[ww]);
	}
	if(huiwen(s)){
		cout << '0';
		return 0;
	}
	long long r=mm-ma;
	long long pq=0;
	long long yy=s.size();
	for(long long i=0;i<=yy/2;i++){
		long long tt=yy-1-i;
		if(s[tt]!=s[i]){
			pq++;
		}
	}
	cout << min(pq,r);
	return 0;
} 
