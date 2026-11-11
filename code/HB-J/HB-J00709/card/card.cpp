#include<bits/stdc++.h>
using namespace std;
int a[500005],t[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        vector<int> b;
        for(int j=1;j<=i;j++)b.push_back(a[j]);
        for(int j=i;j<b.size();j++){
            int f=1000000;
            for(int k=j+1;k<b.size();k++){
                if(b[k]==b[j]){
                    f=k;
                    break;
                }
            }
            int len=b.size();
            for(int k=f+1;k<len;k++){
                b.erase(b.begin()+k);
            }
            b.push_back(a[j+1]);
        }
        for(int j=0;j<b.size();j++){
            t[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<t[i]<<" ";
    return 0;
}
