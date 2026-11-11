#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
unordered_map<int,int> res,vis;
map<int,int> cnt;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        res[a[i]]++;
    }
    /*for(auto u:res){
        cout << u.first  << ","<< u.second << " ";
    }*/
    //cout << "\n";
    for(int i=1 ;i<=n ;i++){
        for(int k=i;k<=n;k++){
            if(res[a[k]]>1){
                for(int j=k+1;j<=n;j++){
                    if(a[k]==a[j]){
                        k=j;
                    }
                }
            }
            cnt[a[k]]++;
            //cout << a[k] << " ";
        }
        //cout << "\n";
    }
    for(auto u:cnt){
        cout <<u.second << " ";
    }
    return 0;
}
