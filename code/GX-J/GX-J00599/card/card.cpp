#include<bits/stdc++.h>
using namespace std;
int b[30001],od[30001],cnt[30001];
long long n,m;
vector<int> a;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    a.push_back(-1);
    for(int i = 1;i <= n;i++) {
        int mid;
        cin>>mid;
        a.push_back(mid);
    }
    for(int i = 1;i <= n;i++){
        cnt[i] = 0;
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1 ;i <= m;i++){//into zero
            od[i] = 0;
            b[i] = 0;
        }
        for(int i = k;i <= n;i++){
            b[a[i]]++;
            if(b[a[i]] >= 2) {
                for(int j = od[a[i]];j <= i - 1;j++){////////search num before place
                    od[j] = -1;
                    b[a[j]] -= 1;
            }
        }
            od[a[i]] = i;
    }
        for(int i = 1 ;i <= m;i++){
            if(b[i] == 1&&od[i] >= 1) cnt[i]++;
        }
    }
    cout<<cnt[1];
    for(int i = 2;i <= m;i++){
        printf(" %d",cnt[i]);
    }
    return 0;
}
