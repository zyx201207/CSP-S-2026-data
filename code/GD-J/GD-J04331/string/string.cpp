#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
const int N=2e5+10; 
int n,len,mid; //len  总长度  
struct range 
{
	int l,r,len;
	char c;
}r[N];  
signed main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int cnt_in=n;
	int cnt_r=1;
	for (int tt=1;tt<=cnt_in;tt++) //n 次输入  
	{
		int cnt;
		char c;
		cin>>cnt>>c; // 几个 什么字
		r[cnt_r].l=len+1,r[cnt_r].r=len+cnt,r[cnt_r].c=c,r[cnt_r].len=r[cnt_r].r-r[cnt_r].l+1;
		len+=cnt;
		cnt_r++;
	}
//	for (int i=1;i<=n;i++) 
//	{
//		cout<<r[i].l<<" "<<r[i].r<<" "<<r[i].len<<endl;
//	}
	int R=n,ans=0,L=1;
	while (R>=L) 
	{
		int t=(r[R].c!=r[L].c?min(r[R].len,r[L].len):0);
		int tt=min(r[R].len,r[L].len); 
//		cout<<"调试"<<L<<"  "<<R<<endl;
		if (r[R].len<r[L].len) //R 用完了  
		{
			ans+=t;
			R--;
			r[L].len-=tt;
		}
		else if (r[R].len==r[L].len) ans+=t,R--,L++;
		else // L 用完了  
		{
			ans+=t;
			L++;
			r[R].len-=tt;
		}
	}
	cout<<ans;
	return 0;	
} 
