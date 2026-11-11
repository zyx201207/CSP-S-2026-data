#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int maxn=1e6;
int n,m,a[maxn],cnt;
struct xx{
	int x,a,b;
}p[maxn];
bool cmp(xx i,xx j){
	if(i.x==j.x) 
	{
		if(i.a==j.a) return i.b>j.b;
		else return i.a<j.a;
	}
	return i.x>j.x;
}
int check(int x,int y){
	int s=0;
	while(x>0)
	{
		if((x%2)&(y%2)==0) s++;
		x/=2;
		y/=2;
	}
	return s;
}
signed main(){
	
	freopen("and.in","r",stdin) , freopen("and.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	bool alllog=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==(1<<(int(log2(a[i])+1)))-1) ;
		else alllog=0;
	}
	if(alllog)
	{
		int s=a[n];
		for(int i=n;i>n-m;i--)
		{
			s&=a[i];
		}
	}
	int man=(1<<(int(log2(a[n])+1)))-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		{
			cnt++;
			p[cnt].x=a[i];
			p[cnt].a=check(man,a[i]);
		}
		p[cnt].b++;
	}
	sort(p+1,p+1+cnt,cmp);
	for(int i=1;m>0;i++)
	{
		//cout<<man<<" ";
		//cout<<p[i].x<<" "<<p[i].a<<" "<<p[i].b<<'\n';
		man&=p[i].x;
		m-=p[i].b;
	}
	cout<<man;
	
	return 0;
}
