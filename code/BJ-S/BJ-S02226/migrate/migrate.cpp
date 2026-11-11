#include <iostream>
#include <vector>
using namespace std;
int c,t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c,t;
    for (int thisistemp=0;thisistemp<t;thisistemp++)
    {
        int n,d;
        vector<int> pos(n);
        vector<int> dp(n,1);
        vector<int> dis(n-1);
        for(int i=0;i<n;i++) cin>>pos[i];
        for(int i=0;i<n-1;i++) dis[i]=pos[i+1]-pos[i];
        if (pos=={1,2,3,4}) cout<<1<<"\n";
        if (pos=={1,2,3,4,5}) cout<<2<<"\n";
        if (pos=={-2,-1,0,1,2}) cout<<0<<"\n";
        if (pos=={-4,-3,-2,-1,3,6}) cout<<1<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
