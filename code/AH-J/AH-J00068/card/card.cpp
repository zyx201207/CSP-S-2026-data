#include <bits/stdc++.h>
using namespace std;
int a[500005] = {};
int y[300005] = {};
int n,m;
void cv(int a[],int i){
    vector <int> h;
    for (int j = i;j<n;j++){
        for (int k = 0;k<h.size();k++){
            if (h[k] == a[j])
            {
                for (int op = k;op<h.size()+1;op++)
                    h.pop_back();
                break;
            }
        }
        h.push_back(a[j]);
    }
    for (int j = 0;j<h.size();j++)
        y[h[j]]++;
    return ;
}
int main(){
    freopen("card.in","w",stdin);
    freopen("card.out","r",stdout);
    cin >> n >> m;
    for (int i = 0;i<n;i++)
    cin >> a[i];
    for (int i = 1;i<=n;i++)
        cv(a,i-1);
    for (int i = 1;i<=m;i++)
    cout << y[i] << ' ';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
