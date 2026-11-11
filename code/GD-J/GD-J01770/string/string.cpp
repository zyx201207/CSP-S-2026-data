#include<bits/stdc++.h>
using namespace std;
int n,l[200005],mid,num;
unsigned long long sum,le,L,R,s[200005],l_s,r_s,L1,L2,R1,R2,yl,yr,ans;
char str[200005];
bool d;
int ys(int num)
{
	if (s[n]%2) return (s[n]/2+1)-num+(s[n]/2+1);
	return (s[n]/2)-num+(s[n]/2+1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>l[i]>>str[i];
		if (l[i]!=l[i-1] && i!=1){
			d=true;
		}
		num=l[i];
		s[i]=s[i-1]+l[i];
	}
	if (d==false)
	{
		for (int i=1;i<=n/2;i++)
		{
			if (str[i]!=str[n+1-i]) sum+=num;
		}
		cout<<sum;
		return 0;
	}
	le=s[n]>>1;
	if (s[n]%2)
	{
		le++;
		L=le-1;
		R=le+1;
		l_s=upper_bound(s+1,s+1+n,L)-s;
		r_s=upper_bound(s+1,s+1+n,R-1)-s;
		if (s[l_s-1]+1==le){
			l_s--;
			L1=s[l_s-1]+1;
			R1=L;
		}
		else
		{
			L1=s[l_s-1]+1;
			R1=L;
		}
		L2=R;
		R2=s[r_s];
	}
	else
	{
		L=le;
		R=le+1;
		l_s=upper_bound(s+1,s+1+n,L)-s;
		r_s=upper_bound(s+1,s+1+n,R)-s;
		if (lower_bound(s+1,s+1+n,L)-s!=l_s)
		{
			L1=s[l_s-2]+1;
			R1=L;
			l_s--;
		}
		else
		{
			L1=s[l_s-1]+1;
			R1=L;
		}
		if (lower_bound(s+1,s+1+n,R)-s!=r_s)
		{
			L2=R;
			R2=s[r_s-1];
			r_s--;
		}
		else{
			L2=R;
			R2=s[r_s];
		}
	}
	do{
		yl=ys(L1);
		yr=ys(R1);
		if (yl>R2)
		{
			if (yr<=L2)
			{
				if (str[l_s]!=str[r_s]) ans+=(R2-L2)+1;
			}
			else
			{
				if (str[l_s]!=str[r_s]) ans+=(R2-yr)+1;
			}
			r_s++;
			L2=s[r_s-1]+1;
			R2=s[r_s];
		}
		else if (yl<R2)
		{
			if (yr<=L2)
			{
				if (str[l_s]!=str[r_s]) ans+=(yl-L2)+1;
			}
			else
			{
				if (str[l_s]!=str[r_s]) ans+=(yl-yr)+1;
			}
			l_s--;
			L1=s[l_s-1]+1;
			R1=s[l_s];
		}
		else
		{
			if (yr<=L2)
			{
				if (str[l_s]!=str[r_s]) ans+=(yl-L2)+1;
			}
			else
			{
				if (str[l_s]!=str[r_s]) ans+=(yl-yr)+1;
			}
			l_s--;
			r_s++;
			L1=s[l_s-1]+1;
			R1=s[l_s];
			L2=s[r_s-1]+1;
			R2=s[r_s];
		}
	}while ((l_s<=0)+(r_s>n)!=2);
	cout<<ans;
	return 0;
}
