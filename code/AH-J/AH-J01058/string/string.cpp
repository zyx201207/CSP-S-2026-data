#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+1;
long long n,q[N],pos,cnt,la;
char a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>q[i]>>a[i];
	pos=n;
	cnt=1;
	while(cnt<pos)
	{
		if(q[cnt]>q[pos])
		{
			if(a[cnt]==a[pos])
			{
				q[cnt]-=q[pos];
				pos--;
			}
			else
			{
				la+=q[pos];
				q[cnt]-=q[pos];
				pos--;
			}
		}
		if(q[cnt]==q[pos])
		{
			if(a[cnt]==a[pos])
			{
				cnt++;
				pos--;
			}
			else
			{
				la+=q[pos];
				pos--;
				cnt++;
			}
		}
		if(q[cnt]<q[pos])
		{
			if(a[cnt]==a[pos])
			{
				q[pos]-=q[cnt];
				cnt++;
			}
			else
			{
				q[pos]-=q[cnt];
				la+=q[cnt];
				cnt++;
			}
		}
	}
	cout<<la;
	return 0;
}
