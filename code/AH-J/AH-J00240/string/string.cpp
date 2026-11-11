#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x;
	char y;
}a[200005];
int n,s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i].x>>a[i].y;
	for(int i=1,j=n; i<j; i++,j--)
	{
		if(a[i].y!=a[j].y)
			s+=min(a[i].x,a[j].x);
		if(a[i].x<a[j].x)
			a[j].x-=a[i].x,j++;
		else if(a[i].x>a[j].x)
			a[i].x-=a[j].x,i--;
	}
	cout<<s;
    return 0;
}
