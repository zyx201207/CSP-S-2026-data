#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
using ll=long long;
const int N=5e5+3;
ll n,m,a[N],qz[N],ans=0;
int main()
{
    ifstream fin("crystal.in");
    ofstream fout("crystal.out");
    ios::sync_with_stdio(0);
    fin>>n>>m;
    qz[0]=0;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        qz[i]=a[i]+qz[i-1];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(((i-mid)*a[i]-(qz[i-1]-qz[mid-1]))<=m)//true
                r=mid;
            else//false
                l=mid+1;
        }
        if(i-l+1>ans)
			ans=i-l+1;
    }
    fout<<ans;
    return 0;
}
