#include<bits/stdc++.h>//注意开不开long long
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,b[N],len,s[N],idx[N];
struct node{int x,cnt;}a[N];
signed main()
{
//Oct31==Dec25?
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
/*
5 8
-3 -1 2 2 7
*/	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b+1,b+1+n);
	b[n+1]=1e18;
	for(int i=1;i<=n;)
	{
		int bi=i;
		while(b[i]==b[bi]) i++;
		a[++len].x=b[bi],a[len].cnt=i-bi;
	}
	n=len;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i].cnt;
	int maxx=a[1].cnt,mm=m,r=len,l=1;
	for(int i=2;i<=n;i++)
	{
		int cha=a[i].x-a[1].x;
		if(mm/cha>=a[i].cnt) maxx+=a[i].cnt,mm-=cha*a[i].cnt;
		else {maxx+=mm/cha,r=i-1;break;}
	}
//	cout<<maxx<<"\n";
	for(int i=2;i<=n;i++)
	{
		int cha=a[i].x-a[i-1].x,val;
		mm+=(s[r]-s[i-1])*cha;
		mm-=(s[i-1]-s[l-1])*cha;
		if(r<i) r=i;
		while(mm<0&&l<r&&(r>i||l<i)) 
		{
			if(r>i&&(l==i||a[i].x-a[l].x<a[r].x-a[i].x)) mm+=(a[r].x-a[i].x)*a[r].cnt,r--;
			else mm+=(a[i].x-a[l].x)*a[l].cnt,l++;
		}
		if(mm<0) continue;
		while(l<r&&(l>1||r<n))
		{
			int hua=0,op;
			if(r<n&&(l==1||a[i].x-a[l-1].x>a[r+1].x-a[i].x)) hua=(a[r+1].x-a[i].x)*a[r+1].cnt,op=0;
			else hua=(a[i].x-a[l-1].x)*a[l-1].cnt,op=1;
			if(mm-hua>=0) 
			{
				if(op==0) mm-=hua,r++;
				else mm-=hua,l--;
			}
			else break;
		}
		val=s[r]-s[l-1];
		if(l>1||r<n)
		{
			if(r<n&&(l==1||a[r+1].x-a[i].x<a[i].x-a[l-1].x)) val+=(mm/(a[r+1].x-a[i].x));
			else val+=(mm/(a[i].x-a[l-1].x));
		}
//		cout<<val<<" "<<mm<<" "<<l<<" "<<r<<" "<<i<<"\n";
		maxx=max(maxx,val);
	}
	cout<<maxx;
	return 0;
}

