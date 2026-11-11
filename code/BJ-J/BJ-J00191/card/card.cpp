#include <bits/stdc++.h>
using namespace std;
struct wee{
    int pos;
}num[300001];
int a[500001];
int sum[300001];
int wee[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int f = 1; f<=n; f++){
        cin>>a[f];
    }
    for(int start = 1; start<=n; start++){
        for(int f = start; f<=n; f++){
            wee[a[f]] = 0;
        }
        for(int f = start; f<=n; f++){
            if(wee[a[f]] == 0){
                wee[a[f]] = 1;
                sum[a[f]]++;
                num[a[f]].pos = f;
            }
            else {
                for(int e = num[a[f]].pos+1; e<f; e++){
                    if(wee[a[e]] == 0) continue;
                    sum[a[e]]--;
                    wee[a[e]] = 0;
                }
                num[a[f]].pos = f;
            }
        }
    }
    for(int f = 1; f<=m; f++){
        cout<<sum[f]<<' ';
    }
    return 0;
}
