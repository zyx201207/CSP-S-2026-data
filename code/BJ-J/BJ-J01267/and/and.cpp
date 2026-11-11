#include <bits/stdc++.h>
using namespace std;
long long a[100086],b[100086];
int p;
int two(long long x)
{
    if(x > 0)
    {
        return two(x/2);
        if(x%2==1)
        {
            b[p] = 1;
        }
        p++;
    }

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    long long andmax = -1;
    for(int i = 1;i <= n;i++){
        if(a[i] > andmax)
        {
            andmax = a[i];
        }
    }
    cout << andmax;
}

