#include<bits/stdc++.h>
#include<string>
using namespace std;
long long n,m,l;
long long s[100020];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			if(s[i]==s[i+j]){
				cout << s[i];
			}
		}
	}
	return 0;
}
