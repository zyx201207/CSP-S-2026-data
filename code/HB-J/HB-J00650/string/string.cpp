#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=200005;
struct node{
	int x;
	char y;
}a[N];
ll n;
char po,b[N];
ll ef[N],flag=1;
ll k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n;
	cin>>a[1].x>>a[1].y;
	po=a[1].y;
	k=a[1].x;
	for(int j=k;j<=k+a[1].x;j++)
	{
		b[j]=a[1].y;
		cout<<b[j];
	}
	for(int i=2;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		for(int j=k;j<=k+a[i].x;j++)
		{
			b[j]=a[i].y;
			cout<<b[j];
		}
		k+=a[i].x;
		if(a[i].y==po&&flag!=0)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==1)
	{
		cout<<0;
		return 0;
	}
	return 0;
}
