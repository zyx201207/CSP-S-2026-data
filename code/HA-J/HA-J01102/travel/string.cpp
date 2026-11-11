#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a[100000]= {0};
	char e[10000000000]= {0};
	char s[10000000000]= {},sd[10000000000]= {};
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i]>>e[i];
		for(int j=0; j<a[i]; j++) {
			s[j]=e[i];
		}
	}
	int qi=sizeof(s);
	sort(s,s+qi);
	for(int i=0; i<qi; i++) {
		if(s[i]==s[i+1]) {
			cout<<0;
			return 0;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
