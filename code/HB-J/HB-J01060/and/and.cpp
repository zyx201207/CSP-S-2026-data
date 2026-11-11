#include<bits/stdc++.h>
using namespace std;
int n,m,a[2*100000],b[2*100000];
bool cmp(int x,int y)
{
	return x>y;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int j=0;
		b[i]=a[i];
		while(m)
		{
			b[i]=b[i]&a[i-j];
			j++;
			m--;
			}	
		}
		sort(b+1,b+n+1,cmp);
		cout<<b[1];
		
}
