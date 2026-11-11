#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],mp[3005],mp2[3005];
vector<int> v;

int main(void)
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(mp2,0,sizeof(mp2));
        v.clear();
        for(int j=i;j<=n;j++){
            mp2[a[j]]++;
            if(mp2[a[j]]==2){
                while(v.back()!=a[j]){
                    mp2[v.back()]--;
                    v.pop_back();
                }
                v.pop_back();
                mp2[a[j]]=1;
            }
            v.push_back(a[j]);
        }
        for(int i=1;i<=m;i++){
            //cout<<mp2[i]<<' ';
            if(mp2[i]) mp[i]++;
        }
       // cout<<endl;
    }
    for(int i=1;i<=m;i++) cout<<mp[i]<<' ';
    cout<<endl;

    return 0;
}
