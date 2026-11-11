#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, a[200005], ans = INT32_MAX;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1, a+n+1, cmp);
    int x = n+1;
    for(int i=1;i<=n;i++){
        if(a[i]==0&&a[i-1]!=0)
            x = i;
        if(a[i]==0&&m>=i){
            cout << 0 << endl;
            return 0;
        }
    }
    n = x-1;
    if(m==n){
        cout << 1;
        for(int i=1;i<=n;i++){
            ans &= a[i];
        }
        cout << ans << endl;
        return 0;
    }
    if(m==1){
        cout << a[1] << endl;
        return 0;
    }
    vector<vector<int>> v(35);
    for(int i=30;i>0;i--){
        for(int j=1;i<=n;j++){
            if(a[j]>=pow(2, i-1)&&a[j]<pow(2, i)){
                v[i].push_back(a[j]);
            }
            else{
                break;
            }
        }
    }
    int num;
    if(m==n-1){
        for(int i=0;i<=30;i++)
            if(v[i].size()!=0)
                num = i;
        for(int i=30;i>num;i--){
            for(int j=0;j<v[i].size();j++)
                ans &= v[i][j];
        }
        int maxx = -1;
        for(int i=0;i<v[num].size();i++){
            int ab = INT32_MAX;
            for(int j=0;j<v[num].size();j++){
                if(i!=j){
                    ab &= a[j];
                }
            }
            maxx = max(maxx, ans&ab);
        }
        ans = maxx;
        cout << ans << endl;
        return 0;
    }
    int maxx = -1, y = 0;
    if(m==2){
        for(int i=30;i>0;i--){
            int size = v[i].size();
            if(size!=0){
                if(size>=m){
                    if(y!=0){
                        for(int j=0;j<size;j++)
                            maxx = max(maxx, y&v[i][j]);
                        ans = maxx;
                    }
                    else{
                        for(int j=0;j<size-1;j++)
                            for(int k=j+1;k<size;k++){
                                maxx = max(maxx, v[i][j]&v[i][k]);
                            }
                        ans = maxx;
                    }
                    cout << ans << endl;
                    return 0;
                }
                else{
                    if(y!=0){
                        cout << (v[i][0]&y) << endl;
                        return 0;
                    }
                    y = a[0];
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}