#include<bits/stdc++.h>
using namespace std;
bool pd=false,dp=false;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a,b;
    string x,r;
    cin>>a>>r>>b>>x;
    if(a==b)
    {
		cout<<1;
		dp=true;
	} 
    else cout<<0;
    if(x[0]==r[0] && x[1]==r[1] && dp==true) 
    {
		cout<<1;
		pd=true;
	}
    else cout<<0;
    if(((r[2]=='D' && x[2]=='E') || (r[2]=='E' && x[2]=='D') || (r[2]=='A' && x[2]=='B')  || (r[2]=='A' && x[2]=='C') ||  (r[2]=='B' && x[2]=='C')  || (r[2]=='B' && x[2]=='A') || (r[2]=='C' && x[2]=='B')  || (r[2]=='C' && x[2]=='A')) && dp==true && pd==true) 
    cout<<1;
    else 
    {
		cout<<0;
	}
    if(((r[2]=='D' && x[2]=='E') || (r[2]=='E' && x[2]=='D') || (r[2]=='A' && x[2]=='B') ||  (r[2]=='B' && x[2]=='C') || (r[2]=='B' && x[2]=='A') || (r[2]=='C' && x[2]=='B')) && pd==true && dp==true)cout<<1;
    else cout<<0;
    fclose(stdin);
    return 0;
}
