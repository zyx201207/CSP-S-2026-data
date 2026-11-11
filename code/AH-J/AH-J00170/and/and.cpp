#include <bits/stdc++.h>
using namespace std;
void awy(int x)
{
    string a;
    string n;
    int cnt=0;
    while(x!=0)
    {
        n[cnt]=x%2;
        x/=2;
        cnt++;
    }
    cnt=0;
    for(int i=n.length()-1;i>=0;i++)
    {
        *a[cnt]=n[i];
        cnt++;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    cin>>n;

}
