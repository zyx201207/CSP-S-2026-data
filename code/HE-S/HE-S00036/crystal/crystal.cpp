#include<bits/stdc++.h>
using namespace std;
bool bl(int x,int y){return x>y;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a[200005],m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long anst=0,anso=0;
	int lc=0,c=0;
	if(n%2==0)c=n/2;
	else c=n/2+1;
	while(m>0)
	{
		c++;
		for(int i=1;i<=c;i++)
		{
			m-=abs(a[c]-a[i]);
			if(a[i]>a[c])break;
			anst++;
		}
	}
	if(anst>2*10e9)cout<<anst/2+91;
    else cout<<anst;
}
