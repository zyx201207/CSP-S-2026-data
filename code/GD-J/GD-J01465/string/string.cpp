#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int a[N],q[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	memset(a,0,sizeof a);
	memset(q,0,sizeof q);
	
	int n;cin>>n;
	int l=1,r=0,cnt=0,pd=1;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],r+=a[i],q[i]+=a[i]+q[i-1];
//	for(int i=1;i<=n;i++)cout<<q[i]<<" ";cout<<"\n";
	int mid=(r+1)/2;
	r=r-a[n]+1;
	while(l<r)
	{
		int idl=lower_bound(q+1,q+n+1,l)-q;
		int idr=lower_bound(q+1,q+n+1,r)-q;
//		cout<<"1:"<<idl<<" "<<idr<<"\n";
		if(idl==idr)break;
		int lk=q[idl]-l+1;
		int rk=q[idr]-r+1;
//		cout<<"2:"<<q[idl]<<" "<<l<<"\n";
//		cout<<"3:"<<q[idr]<<" "<<r<<"\n";
		int mm=min(lk,rk);
//		cout<<"lk:"<<lk<<" "<<"rk:"<<rk<<"\n";
		if(c[idl]!=c[idr])
		{
			if(pd==1)cnt+=mm,l+=mm,r=q[n]-mm,q[n]-=mm;
			else if(l+mm<=mid)cnt+=mm,l+=mm,r-=mm;
			else{cnt+=mid-l+1;break;}
		}
		else if(pd==1) l+=mm,r=q[n]-mm,q[n]-=mm;
		else if(pd==0)l+=mm,r-=mm; 
//		cout<<"4:"<<l<<" "<<r<<"\n";
		pd=0;
//		cout<<"cnt:"<<cnt<<"\n";
	}
	cout<<cnt;
}
/*
3 
1 a
3 c
2 a

3
2 a
2 b
1 c

4
3 a
5 b
2 c
99 d

4
1 a
1 a
1 b
1 b
*/
