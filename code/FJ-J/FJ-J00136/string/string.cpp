#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long s,t,l;
	char c;
}a[200005];
int n,j;
long long len=0,mid,ans=0;
stack<node> st;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].c;
		a[i].s=len;a[i].t=len+a[i].l;
		len+=a[i].l;
	}
	//cout<<len<<' ';
	mid=len/2+1;
	//cout<<mid<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i].s<mid && a[i].t<mid)
		{
			st.push(a[i]);	
		}
		else if(a[i].s<mid && a[i].t>mid)
		{
			st.push((node){a[i].s,mid,mid-a[i].s,a[i].c});
			//cout<<mid-a[i].s-1<<' '<<a[i].s<<' '<<mid-1<<endl;
			a[i].s=mid;
			j=i;
			break;
		}
		//cout<<a[i].l<<' '<<a[i].s<<' '<<a[i].t<<endl;
	}
	//cout<<j<<' ';
	while(!st.empty())
	{
		node h=st.top();
		st.pop();
		while(h.l>0)
		{
			if(a[j].l>=h.l)
			{
				a[j].l-=h.l;
				ans+=(a[j].c==h.c?0:h.l);
				break;
			}
			else if(a[j].l<h.l)
			{
				h.l-=a[j].l;
				ans+=(a[j].c==h.c?0:a[j].l);
				j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
