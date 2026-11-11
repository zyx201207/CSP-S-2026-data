#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[600000];
int b[600000];
int c[600000];
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	bool s[600000]={0};
	int l=1,r=n;
	int i=1,p=1; 
	int ans=1;
	while (a[r]!=0) {
		if (l==r) {
			for (int k=p;k<=i;k++) {
				s[b[k]]=0;
				c[b[k]]++;
				ans++;
			}	
			p=i;
			r=r+ans;
			ans=1;
			i++;l++;
		}
		else {
			if (!s[a[l]]) {
				b[i]=a[l];
				s[a[l]]=1;
				i++;
			}
			else {
				int y=1;
				for (int j=p;j<=i;j++) {
					s[b[j]]=0;
					a[r+y]=b[j];
					y++;
				}
				b[i]=a[l];
				p=i;
				i++;
			}
			l++;	
		}
	}
	for (int x=1;x<=m;x++) {
		cout<<c[x]<<" ";
	}
	
	
	
	return 0;
}
 
