#include<bits/stdc++.h>
using namespace std;
long long m,n;
int a[20007],ans[20007];
vector<int> b;
void card(int k){
    for(int i=k;i<m;i++){
            int flag=0;
        for(int j=k;j<b.size();j++){
            if(b[j]==a[i]){
                flag=1;
            }if(flag==1){
                delete(b[j]);
            }
        }b.push_back(a[i]);
    }for(int i=1;i<=n;i++){
        ans[b[i]]++;
    }return;
}
int main(){
    cin>>m>>n;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }for(int i=0;i<m;i++){
        b.clear();
        card(i);
    }for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}