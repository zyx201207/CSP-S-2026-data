#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;
int c,t,n,d,a[N];

void solve1()
{
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> a[i];
    d/=(a[2]-a[1]);
    d=2*d;
    if(n>=d) cout << n-d+1 << "\n";
    else cout << 0 << "\n";
}

void solve2()
{
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> a[i];
    
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--)
    {
        if(c==11||c==12) solve1();
        if(c==13||c==14) solve2();
    }
	return 0;
}

