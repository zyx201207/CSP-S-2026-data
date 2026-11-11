#include <iostream>
#include <vector>
using namespace std;
long long n,m;
int a[500050];
int sm[300050];
vector<int> tab;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i-1;j<=n;j++){
            for(int k=0;k<tab.size();k++){
                if(tab[k]==a[j]){
                    tab.erase(tab.begin()+k-1,tab.end());
                    break;
                }

            }
            tab.push_back(a[j]);
        }
        for(int k=0;k<tab.size();k++){
            sm[tab[k]-1]++;
        }
        tab.clear();
    }

    for(int i=0;i<m;i++){
        cout<<sm[i]<<" ";
    }

    return 0;
}
