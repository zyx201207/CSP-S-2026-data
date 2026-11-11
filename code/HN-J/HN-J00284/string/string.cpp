#include<bits/stdc++.h>
using namespace std;
char c[200005];
int n,a[200005];
long long tt;
int lef,rig;//第几个数组 
int l = 1,r,b;//数组内编号 
//bool hw(int q,int z)
//{
//	for(int i = q;i <= (q + z) / 2;i ++)
//		if(s[i] != s[z - i])
//			return 0;
//	return 1;
//}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i ++)
		scanf("%d %c ",&a[i],&c[i]);
	
	
	rig = n;
	r = a[rig];
	l = a[lef];
	while(lef <= rig)
	{
		if(lef >= rig)
			break;
		
//		if(r < l)
//		{
//			if(c[lef] != c[rig])
//				tt += r;
//			l -= r;
//			r -= r;
//		}
//		else
//		{
//			if(c[lef] != c[rig])
//				tt += l;
//			r -= l;
//			l -= l;
//		}
		if(c[lef] != c[rig])
				tt += min(l,r);
		b = l;
		l -= min(l,r);
		r -= min(b,r);
		if(r == 0)
		{
			rig --;
			r = a[rig];
		}
		if(l == 0)
		{
			lef ++;
			l = a[lef];
		}
	}
	
	cout<<tt;








	return 0;
}

