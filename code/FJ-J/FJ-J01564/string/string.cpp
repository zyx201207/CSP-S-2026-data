#include<bits/stdc++.h>
using namespace std;
long long a[10000],ans;
int n;
char c[100000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	for (long long j=1;j<=a[i];j++){
    		s=s+c[i];
		}
	}
	for (int l=0;l<s.size()/2;l++){
		long long r=s.size()-1-l;
		if (s[l]!=s[r]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
