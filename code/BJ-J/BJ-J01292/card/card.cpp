#include<bits/stdc++.h>
using namespace std;
int t[10005];
int sum[10005];
bool use[10005];
bool alive[100005];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> t[i];
    }
    for(int q=1;q<=n;q++){
            memset(alive,0,sizeof(alive));
            memset(use,0,sizeof(use));
        for(int i=q;i<=n;i++){
            if(use[t[i]]){
                for(int j=i-1;j>=q;j--){
                if(t[j]==t[i]&&!use[j]){
                    break;
                }
                use[j]=0;
                alive[j]=1;
            }
            }else{
            use[t[i]]=1;
            }
        }
    bool vised[10005];
        memset(vised,0,sizeof(vised));
        for(int i=q;i<=n;i++){
            if(!alive[i]&&!vised[t[i]]){
                    //cerr << i << "isok";
                sum[t[i]]++;
                vised[t[i]]=1;
            }
        }
        //cerr << endl;
    }
    for(int i=1;i<=m;i++){
        cout << sum[i] <<" ";
    }
    return 0;
}
