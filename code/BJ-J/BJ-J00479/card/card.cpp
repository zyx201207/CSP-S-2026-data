#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int arr[n+1];
    int cnt[m+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        int use[m+1]={0};
        vector<int> last;
        for(int j=i;j<=n;j++){
            if(use[arr[j]]==0){
                last.push_back(arr[j]);
                use[arr[j]]=1;
            }
            else{
                while(true){
                    if(last[last.size()-1]!=arr[j]){
                        last.pop_back();
                    }
                    else{
                        break;
                    }
                }
            }
        }
        for(int j=0;j<last.size()-1;j++){
            cnt[last[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
