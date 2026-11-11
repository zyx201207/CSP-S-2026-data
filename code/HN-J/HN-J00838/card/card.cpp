#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005],c;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
	{
		b[a[i]]++;
	}
	for(int i=0;i<m;i++)
		cout<<b[i];
	return 0;
}
