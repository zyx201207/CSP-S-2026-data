#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int n,a[maxn],l,li,r,ri,s;
char c[maxn];
signed main(){
	
	freopen("string.in","r",stdin) , freopen("string.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	l=0,li=0,r=0,ri=n+1;
	for(;li<ri;)
	{
		if(l==0) li++ , l=a[li];
		if(r==0) ri-- , r=a[ri];
		if(li==ri) break;
		if(l>=r) //и╬ср╠ъ 
		{
			if(c[li]!=c[ri]) 
			{
				s+=r;
//				cout<<li<<" "<<ri<<" "<<l<<" "<<r<<"\n";
			}
			l-=r;
			ri--;
			r=a[ri];
		}
		else
		{
			if(c[li]!=c[ri]) 
			{
				s+=l;
//				cout<<li<<" "<<ri<<" "<<l<<" "<<r<<"\n";
			}
			r-=l;
			li++;
			l=a[li];
		}
	}
	cout<<s;
	
	return 0;
}
