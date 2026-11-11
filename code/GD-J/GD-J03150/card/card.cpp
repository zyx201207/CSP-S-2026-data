#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
    	cin >> a[i];
	}
	for (int i=1;i<=n;i++) {
		int b[500005];
		string s="";
		for (int j=1;j<=n;j++) b[i]=a[i];
		for (int j=i;j<=n;j++) {
			if (s.find(char(b[j]+'0'))==-1) s+=char(b[j]+'0');
			else {
				s.erase(s.find(char(b[j]+'0')),s.size());
				s+=char(b[j]+'0'); 
			}
		}
		for (int j=0;j<s.size();j++) c[s[i]-'0']++;
	}
	for (int i=1;i<=m;i++) cout <<c[i]<<' ';
    return 0;
}
