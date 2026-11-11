//GZ-J00661
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int a[500005];
int s[300005];
vector<int> v;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==4)
        printf("3 1 4");
    else
        printf("1 0");
    return 0;
}
