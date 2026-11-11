#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,c=0;
	cin>>n;
	string s;
	long long a;
	char b;
	long long nnn =0;
	long long ds = 0;
	for(long long i = 0;i<n;i++){
		cin >> a >> b;
		ds += a;
		for(long long j = 0;j<a;j++){
			s[nnn] = b;
			nnn++;
	}
}
		long long nn = 0;
		c = ds/2;
		long long s1[ds/2];
		for(long long i = ds/2 -1;i>=0;i--){
			s1[i] = s[nn];
			nn++;
		}
		if(ds%2 == 1) {
		for(long long i = 0;i<ds/2;i++){
			if(s1[i] == s[i + ds/2+1]){
				c--;
			}
		}
	}
	else{
		for(long long i = 0;i<ds/2;i++){
			if(s1[i] == s[i + ds/2]){
				c--;
			}
		}		
	}
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
