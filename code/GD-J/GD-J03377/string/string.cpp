#include<bits/stdc++.h>
using namespace std;
long long n,lt,rt,ls,rs,s,t,tt,sum,a[200005];
char ln,rn,c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
//		cout<<sum; 
	}
	long long l=1,r=n;
	while(1)
	{
		if(t==0)
		{
			lt=min(a[l],sum/2-ls),rt=min(a[r],sum/2-rs);
			t=max(lt-rt,rt-lt);
			if(c[l]!=c[r])
			{
				s+=min(lt,rt);
			}
			ls+=lt,rs+=rt;
			if(lt>rt)
			{
				tt=1;
				ln=c[l];
				r--;
			}
			else if(lt<rt)
			{
				tt=0;
				rn=c[r];
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
		else
		{
			if(tt==1)
			{
				lt=t,rt=min(a[r],sum/2-rs);
				t=max(lt-rt,rt-lt);
				if(ln!=c[r])
				{
					s+=min(lt,rt);
				}
				rs+=rt;
				if(lt>rt)
				{
					tt=1;
					ln=c[l];
					r--;
				}
				else if(lt<rt)
				{
					tt=0;
					rn=c[r];
					l++;
				}
				else
				{
					l++;
					r--;
				}
			}
			else
			{
				lt=min(a[l],sum/2-ls),rt=t;
				t=max(lt-rt,rt-lt);
				if(c[l]!=rn)
				{
					s+=min(lt,rt);
				}
				ls+=lt;
				if(lt>rt)
				{
					tt=1;
					ln=c[l];
					r--;
				}
				else if(lt<rt)
				{
					tt=0;
					rn=c[r];
					l++;
				}
				else
				{
					l++;
					r--;
				}
			}
		}
		if(ls==sum/2&&rs==sum/2)
		{
			break;
		}
	}
	cout<<s; 
	return 0;
}
