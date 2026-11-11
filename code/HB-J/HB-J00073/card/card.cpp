#include <bits/stdc++.h>
using namespace std;
int n,m,ans[300005],a[500005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= n;i++){
        vector<int> temp;
        for(int j = i;j <= n;j++){
            int pos = -1;
            for(int k = 0;k < temp.size();k++){
                if(temp[k]==a[j]){
                    pos = k;
                    break;
                }
            }

            if(pos!=-1){
                for(int k = pos;k < temp.size();){
                    temp.pop_back();
                }
            }


            temp.push_back(a[j]);

        }
        for(int j = 0;j < temp.size();j++){
            ans[temp[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
