#include <iostream>
#include <list>
#include <iterator>

using namespace std;

struct node
{
	long long a,s;
	char c;
}a[1000010],pre[1000010],nxt[1000010];

long long n,lp,ln,cnt;
list<node>l;

void split(list<node> ::iterator i,long long x)
{
	long long ta=i->a,ts=i->s;
	node tp;
	i->a=x;
	i->s-=(ta-x);
	tp.a=ta-x;
	tp.s=ts;
	tp.c=i->c;
	l.insert(next(i),tp);
}

void print()
{
	cerr<<"l:";for(list<node> ::iterator i=l.begin();i!=l.end();i++)cerr<<i->a<<"|"<<i->c<<"|"<<i->s<<" ";cerr<<endl;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].c;
		a[i].s=a[i-1].s+a[i].a;
	}
	for(long long i=1;i<=n;i++)
	{
		if(a[i].s*2>=a[n].s)
		{
			//cerr<<"|"<<i<<" "<<a[i].s<<" "<<a[n].s<<endl;
			lp=ln=max(i,n-i+1);
			if(a[n].s&1)a[i].a--;
			long long tmp=a[n].s/2-a[i-1].s;
			//cerr<<"||tmp:"<<tmp<<endl;
			for(long long j=1;j<i;j++)
			{
				pre[j].a=a[j].a;
				pre[j].c=a[j].c;
				pre[j].s=a[j].s;
			}
			pre[i].a=tmp;
			pre[i].c=a[i].c;
			pre[i].s=pre[i-1].s+tmp;
			for(long long j=n;j>i;j--)
			{
				nxt[n-j+1].a=a[j].a;
				nxt[n-j+1].c=a[j].c;
				nxt[n-j+1].s=nxt[n-j].s+a[j].a;
			}
			nxt[n-i+1].a=a[i].a-tmp;
			nxt[n-i+1].c=a[i].c;
			nxt[n-i+1].s=nxt[n-i].s+a[i].a-tmp;
			break;
		}
	}
	//cerr<<"pre:";for(long long i=1;i<=lp;i++)cerr<<pre[i].a<<"|"<<pre[i].c<<"|"<<pre[i].s<<" ";cerr<<endl;
	//cerr<<"nxt:";for(long long i=1;i<=ln;i++)cerr<<nxt[i].a<<"|"<<nxt[i].c<<"|"<<nxt[i].s<<" ";cerr<<endl;
	l.push_back({0,0,0});
	for(long long i=1;i<=lp;i++)l.push_back(pre[i]);
	//print();
	//l.push_back({0,0x7fffffff,0});
	list<node> ::iterator ll=l.begin(),rr=l.begin();
	for(long long i=1;i<=ln;i++)
	{
		//cerr<<"|||"<<i<<endl;
		long long lb=nxt[i-1].s+1,rb=nxt[i].s;
		if(nxt[i].a==0)break;
		while(ll!=l.end()&&ll->s<lb)ll++;
		split(ll,lb-prev(ll)->s-1);
		while(rr!=l.end()&&rr->s<rb)rr++;
		split(rr,rb-prev(rr)->s);
		//print();
		//cerr<<"area:";for(list<node> ::iterator i=next(ll);i!=next(rr);i++)cerr<<i->a<<"|"<<i->c<<"|"<<i->s<<" ";cerr<<endl;
		for(list<node> ::iterator j=next(ll);j!=next(rr);j++)
		{
			if(j->c!=nxt[i].c)cnt+=j->a;
		}
	} 
	/*
	for(long long l=1,r=1;l<=lp&&r<=ln;l++)
	{
		if(pre[l].s<=nxt[r].s)
		{
			if(nxt[r].c!=pre[l].c)cnt+=(pre[l].s-pre[l-1].s);
			continue;
		} 
		while(nxt[r].s<=pre[l-1].s)r++;
		if(nxt[r].c!=pre[l].c)cnt+=(nxt[r].s-pre[l-1].s);
		if(nxt[r].s<=pre[l].s)r++;
		while(nxt[r].s<=pre[l].s)
		{
			if(nxt[r].c!=pre[l].c)cnt+=nxt[r].s-nxt[r-1].s;
			r++;
		}
		if(nxt[r-1].s<=pre[l].s&&nxt[r].c!=pre[l].c)cnt+=pre[l].s-nxt[r-1].s;
	}
	*/
	cout<<cnt;
}
/*
4
1 a
1 b
1 a
4 b

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

2
2 a
3 a

3
2 a
2 b
1 c
*/
