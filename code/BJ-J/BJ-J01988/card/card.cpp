#include <bits/stdc++.h>

using namespace std;
long long n,m,a[50005],ans,cou[30005];
void game(int num){


    return ;
}
int main()
{
    freopen("card.in","r",stdin);freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> lis;
        lis.push_back(a[i]);
        for(int j=i+1;j<=n;j++){
            for(int z=0;z<int(lis.size());z++){
                if(lis[z]==a[j]){
                    lis.resize(z);
                }
                lis.push_back(lis[z]);
            }
        }
        cou[lis[0]]++;
        lis.erase(lis.begin());
    }
    for(int i=0;i<m;i++){
        cout<<cou[i]<<" ";
    }
    return 0;
}