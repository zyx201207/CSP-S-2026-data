#include<bits/stdc++.h>
using namespace std;
int a[500010];
vector<int>card;
int cnt[300010];
bool b[5010][3010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    /*for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            bool flag=0;
            int first=0;
            for(size_t k=1;k<=card.size();k++){
                if(k==j){
                    flag=1;
                    first=k;
                }
            }
            if(flag==0){
                card.push_back(a[j]);
            }else{
                for(size_t k=card.size();k>=first;k++){
                    card.pop_back();
                }
                card.push_back(a[j]);
            }
        }
        bool flag=0;
        for(int j=1;j<=m;j++){
            for(size_t k=1;k<=card.size();k++){
                if(card[k]==j){
                    b[i][j]==true;
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(b[j][i]==true){
                cnt[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }*/
    for(int i=1;i<=m;i++){
        cout<<n<<' ';
    }
    return 0;
}
