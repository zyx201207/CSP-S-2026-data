#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int ans[500005];
void rungame(int ju)
{
    bool b[500005]={0};
    stack<int> s;
    for(int i=ju;i<=n;i++)
    {
        if(!b[a[i]])
        {
            s.push(a[i]);
            b[a[i]]=1;
        }else{
            while(s.top()!=a[i])
            {
                b[s.top()]=0;
                s.pop();
            }
            //1 3 2 3->rm[3 2]==rm[2 3]
        }
    }
    //cout<<"\nNUM"<<ju<<'\n';
    while(!s.empty())
    {
        ans[s.top()]++;
        //cout<<s.top()<<' ';
        s.pop();
    }
}
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        rungame(i);
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    cout<<'\n';
	return 0;
}