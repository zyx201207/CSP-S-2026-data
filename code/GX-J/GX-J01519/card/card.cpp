#include<iostream>
#include<stack>
#include<map>
using namespace std;

stack<int> desk;
map<int,bool> d;
int deck[500005];
int ans[300005];
int n,m;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>deck[i];
    for(int r=0;r<n;r++)
    {
        for(int i=r;i<n;i++)
        {
            if(d[deck[i]]!=true)
            {
                desk.push(deck[i]);
                d[deck[i]]=true;
            }
            else
            {
                while(desk.top()!=deck[i] && !desk.empty())
                {
                    d[desk.top()]=false;
                    desk.pop();
                }
            }

        }
        while(!desk.empty())
        {
            ans[desk.top()]++;
            desk.pop();
        }
        d.clear();
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
