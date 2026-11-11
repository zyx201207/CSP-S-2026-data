//What a fucking coding problem!
#include<bits/stdc++.h>
using namespace std;
int a[500005],v[300005];
struct tpo
{
    bool c;
    int h;
};
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        map<int,tpo> t;
        queue<int> c;
        for(int j=i;j<=n;j++)
        {
            if(t[a[j]].c)
            {
//                tpo tt=t[a[j]];
//                for(int l=0;l<=j;l++)
//                {
//                    t[c.front()].c=false;
//                    t[c.front()].h=0;
//                    c.pop();
//                }
//                for(int l=0;l<c.size();l++)
//                {
//                    cout<<c.front()<<"T ";
//                    c.push(c.front());
//                    c.pop();
//                }
//                cout<<endl;
                for(int l=0;l<t[a[j]].h-1;l++)
                {
                    c.push(c.front());
                    c.pop();
                }
//                for(int l=0;l<c.size();l++)
//                {
//                    cout<<c.front()<<"T ";
//                    c.push(c.front());
//                    c.pop();
//                }
//                cout<<endl;
                for(int l=t[a[j]].h;l<j;l++)
                {
                    t[c.front()].c=false;
                    t[c.front()].h=0;
                    c.pop();
                }
//                for(int l=0;l<c.size();l++)
//                {
//                    cout<<c.front()<<" T";
//                    c.push(c.front());
//                    c.pop();
//                }
//                cout<<endl;
//                for(int l=0;l<c.size();l++) cout<<l<<" ";
//                cout<<endl;
//                cout<<"CB";,c.begin()+j-1
                t[a[j]].c=true;
                t[a[j]].h=j;
                c.push(a[j]);
            }
            else
            {
                t[a[j]].c=true;
                t[a[j]].h=j;
                c.push(a[j]);
            }
        }
//        cout<<"S"<<endl;
//        if(!(c.empty())
//        {
//            for(int l=0;l<c.size();l++)
//            {
//                cout<<c.front()<<" ";
//                c.push(c.front());
//                c.pop();
//            }
//        }
//        cout<<"E"<<endl;
        for(int k=1;k<=m;k++)
        {
            if(t[k].c) v[k]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
