#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+11;
vector<int> v[N];
vector<int> a[N];
vector<int> id[N];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;    cin >> n >> m;
    int mx = 0;
    for(int i=1;i<=n;i++){
        int x;  cin >> x;
        while(x){
            int t = x%2;
            a[i].push_back(t);
            x/=2;
        }

        mx = max(mx,(int)a[i].size());

    }

    //cout << mx << endl;
    for(int i=1;i<=n;i++){
    /*
        if((int)a[i].size()<mx) {
             cout << (int)a[i].size()<<" ";
            int le = (int)a[i].size();
            for(int i=le-1;i<mx;i++) a[i].push_back(0);
        }
        */
        for(int j=mx-1;j>=0;j--){
            if(j>=(int)a[i].size()) v[i].push_back(0);
            else v[i].push_back(a[i][j]);
        }
/*
        for(auto x:v[i]){
            cout << x;
        }
        cout << endl;
        */

    }
    string ans = "";
    for(int i=mx-1;i>=0;i--){
        int cnt = 0;
        if(i==mx-1){
            for(int j=1;j<=n;j++){
                if(v[j][i]==1) cnt++;
                id[i+1].push_back(j);
            }
        }
        else{
            for(auto j:id[i+1]){
                if(v[j][i]==1) cnt++;

            }
        }
        if(cnt>=m){
            for(auto j:id[i+1]){
                if(v[j][i]==1) id[i].push_back(j);
            }
            ans+='1';
        }else{
            ans+='0';
            for(auto j:id[i+1]){
                id[i].push_back(j);
            }
        }
    }

    int ans2 = 0;
    for(int i=0;i<ans.size();i++){
        ans2 = ans2*2+(ans[i]-'0');

    }

    cout << ans2;
    return 0;
}
