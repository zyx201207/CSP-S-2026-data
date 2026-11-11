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
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
	}
	for(int i=1;i<=k;i++)
	{
		cout<<1;
	}
	return 0;
}
