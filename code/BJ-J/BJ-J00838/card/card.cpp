#include <iostream>
#include <stack>
using namespace std;
int n,m,turn[500000]={},b[500000];
stack <int> a;
void cardgame(int x)
{
    int tag[500000]={0};
    for(int i=x-1;i<n;i++)
    {
        if(tag[b[i]==0])
        {
            tag[b[i]]=1;
            a.push(b[i]);
        }
        else
        {
            while(a.top()!=b[i])
            {
                a.pop();
            }
            a.pop();
        }
    }
    while(!a.empty())
    {
        turn[a.top()]=turn[a.top()]+1;
        a.pop();
    }
    if(x+1>n)
    {
        cardgame(x+1);
    }
    else
    {
        return;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    cardgame(1);
    for(int i=1;i<=m;i++)
    {
        cout<<turn[i];
    }
    return 0;
}
