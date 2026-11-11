#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[300005];
int c[300005];
int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--)
		{
			c[a[j]]++;
			if(b[a[j]]>1){
				break;
			}
		}
		b[a[i]]--;
	}
	for(int i=1;i<=m;i++){
		cout <<c[i]<<" ";
	}
	return 0;
}
