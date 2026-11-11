#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],l,cnt;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	l=s.size();
	if(l%2==0){
		for(int i=1;i<=l/2;i++){
			if(s[i]!=s[l-i]){
				cnt++;
			}
		}
		if(s[l/2-1]!=s[l/2]){
			cnt++;
		}
	}
	else{
		if(n%2!=0){
			for(int i=1;i<=n/2+1;i++){
				if(s[i]!=s[l-i+1]){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

