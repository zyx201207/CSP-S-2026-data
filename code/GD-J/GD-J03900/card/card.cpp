#include <bits/stdc++.h>
#define int long long
#define For(i,n) for(int i=1;i<=n;i++)
#define Fors(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int N0=8192,N=524288;
int n,m,a[N],cnt[N],cntA[N];
bool in[N0];
stack<int> S; 

void Solve()
{
	For(i,n)
	{
		memset(in,false,sizeof(in));
		while(!S.empty()) S.pop();	//S.clear()
		
		Fors(j,i,n)
		{
			int k=a[j];
			if(in[k])
			{
				while(!S.empty())
				{
					int top=S.top();
					in[top]=false;
					S.pop();
					if(top==k) break;
				}
			}
			S.push(k);
			in[k]=true;
		}
		For(j,m) cnt[j]+=in[j];
	}
	For(i,m)
		cout<<cnt[i]<<' ';
}

void Solve_m2()
{
	int cnt1=0,cnt2=0;
	For(i,n)
		if(a[i]==1) cnt1++;
		else if(a[i]==2) cnt2++;
	if(a[n]==1) cout<<n<<' '<<cnt2;
	else if(a[n]==2) cout<<cnt1<<' '<<n;
}

void SolveA()
{
	For(i,n) cntA[a[i]]++;
	For(i,m) cntA[i]=cntA[i-1]+cntA[i];
	For(i,m) cout<<cntA[i]<<' ';
}

void SolveB()
{
	
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	For(i,n) cin>>a[i];
	
	if(n<=5000)
	{
		Solve();
		return 0;
	}
	
	bool solve_m2=true;
	For(i,n) if(not(a[i]==1 or a[i]==2))
		solve_m2=false;
	if(solve_m2)
	{
		Solve_m2();
		return 0;
	}
	
	bool solvea=true;
	For(i,n-1) if(not(a[i]<=a[i+1]))
		solvea=false;
	if(solvea)
	{
		SolveA();
		return 0;
	}
	
	SolveB();
	return 0;
}
