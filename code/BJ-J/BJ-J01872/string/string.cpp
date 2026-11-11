#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long w;
    char c;
    string s = "";
    for(long long i = 0;i<n;i++){
		cin>>w>>c;
		for(long long j = 0;j<w;j++){
			s+=c;
		}
	}
	long long l = s.length();
	char a[l/2];
	char b[l/2];
	for(long long i = 0;i<l/2;i++){
		a[i] = s[i];
		b[i] = s[l-i-1];
	}
	long long q = 0;
	for(long long i = 0;i<l/2;i++){
		if(!(a[i] == b[i])){
			q++;
		}	
	}
	cout<<q;
	return 0;
}
