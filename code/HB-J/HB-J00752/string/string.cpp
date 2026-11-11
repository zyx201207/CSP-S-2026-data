#include <bits/stdc++.h>
using namespace std;

struct men
{
    long long number;
    char shu;
};
vector<men>a;int cnt;
void cha()
{
    int geshu=0;
    for(int i=0;i<cnt/2;i++)
    {
        long long d=0,e=0;
        while(a[i].number-d>0)
        {
            if(a[i].shu==a[cnt-i-e-1].shu)
            {
                a[i].number-=min(a[i].number-d,a[cnt-i-e-1].number);
                a[cnt-i-e-1].number-=min(a[i].number-d,a[cnt-i-e-1].number);
            }
            else{
                d+=a[cnt-i-e-1].number;
            }
            e++;
        }
    }
    return ;
}
long long he()
{
    long long cmt=0;
    for(int i=0;i<cnt;i++)
    {
        cmt+=a[i].number;
    }
    return cmt;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        men b;
        cin>>b.number>>b.shu;
        if(i==1)
        {
            a.push_back(b);
            ++cnt;
            continue;
        }
        if(a.back().shu==b.shu)
            a.back().number+=b.number;
        else
        {
            a.push_back(b);
            cnt++;
        }
    }
    cha();
    /*for(int i=0;i<cnt;i++)
    {
        cout<<a[i].number<<a[i].shu<<endl;
    }*/
    cout<<he()/2;
    return 0;
}
