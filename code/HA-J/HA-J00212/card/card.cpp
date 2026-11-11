#include<bits/stdc++.h>
using namespace std;

int n, m, a[500001], k[300001], s[300001], top=0;
//set<int> s[300001];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	memset(k, 0, sizeof k);
	for (int i=1;i<=n;i++) {
		memset(s, 0, sizeof s);
		top=0;
		for (int j=i;j<=n;j++) {
			bool t=1;
			int x=0;
			for (int l=1;l<=top && t;l++)
				if (s[l]==a[j])
					x=l, t=0;
			if (t)
				s[++top]=a[j];
			else {
				top=x;
				s[top]=a[j];
			}
		}
		for (int j=1;j<=top;j++)
			k[s[j]]++;
	}
	for (int i=1;i<=m;i++)
		cout<<k[i]<<" ";
	return 0;
}
