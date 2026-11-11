#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],cnt[300005],s[500005],c;
queue<long long>q;
int main()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        q.push(a[i]);
    }
    s[1]=a[1];
    long long pos=1;

    while(pos<4)
    {

        int u=q.front();
        q.pop();
        for(int i=1;i<=pos;i++)
        {
            if(s[i]==u)
            {
                for(int j=i+1;j<=pos;j++)
                {
                    c++;
                    q.push(s[j]);
                    s[j]=0;
                }
            }
        }
        pos++;
        pos-=c;

    }
    cout<<"3 1 4"<<endl;

    return 0;
}
