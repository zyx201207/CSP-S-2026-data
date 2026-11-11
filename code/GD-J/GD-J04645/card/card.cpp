#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],t=0,c=0,s[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		t=0;
		c=0;
		for(int l=i;l<=n;l++){
			for(int j=1;j<=c;j++){
				if(b[j]==a[l]){
					t=j-1;
					c=j-1;
				}
			}
			t+=1;
			c++;
			b[t]=a[l];
		}
		for(int l=1;l<=c;l++){
			s[b[l]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
