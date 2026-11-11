#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
char d[N];
struct node{
	long long cnt;
	char c;
}l[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>d[i];
	}
	long long ct=a[1];
	char cc=d[1];
	int m=0;
	for(int i=2;i<=n;i++)
	{
		if(d[i]==cc)
		{
			ct+=a[i];
		}
		else 
		{
			l[++m].cnt=ct;
			l[m].c=cc;
			cc=d[i];
			ct=a[i];
		}
	}
	l[++m].cnt=ct;
	l[m].c=cc;
//	for(int i=1;i<=m;i++)
//	{
//		cout<<l[i].cnt<<" "<<l[i].c<<'\n';
//	}
	int i=1,j=m;
	long long ans=0;
	while(i<j)
	{
		if(i+1==j)
		{
			if(l[i].c==l[j].c)break;
			if(l[i].cnt==l[j].cnt)
			{
				ans+=l[i].cnt;
				break;
			}
//			long long mid=(l[i].cnt+l[j].cnt)/2+(l[i].cnt+l[j].cnt)%2;
//			long long o=(l[i].cnt>l[j].cnt)?l[i].cnt:l[j].cnt;
//			ans+=l[i].cnt+l[j].cnt-(l[i].cnt+l[j].cnt)%2-(o-mid)*2;
			ans+=(l[i].cnt<l[j].cnt)?l[i].cnt:l[j].cnt; 
			break;
		}
		if(l[i].c==l[j].c)
		{
			if(l[i].cnt<l[j].cnt)l[j].cnt-=l[i].cnt,i++;
			else if(l[i].cnt==l[j].cnt)i++,j--;
			else l[i].cnt-=l[j].cnt,j--;
		}
		else
		{
			if(l[i].cnt<l[j].cnt)
			{
				ans+=l[i].cnt;
				l[j].cnt-=l[i].cnt;
				i++;
			}
			else if(l[i].cnt==l[j].cnt)
			{
				ans+=l[i].cnt;
				i++,j--;
			}
			else 
			{
				ans+=l[j].cnt;	
				l[i].cnt-=l[j].cnt;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

