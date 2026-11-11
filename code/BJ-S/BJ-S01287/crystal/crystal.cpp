#include <bits/stdc++.h>
using namespace std;
int a[int (5.1e5)];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    int left = m;
    for (int i = 0; i<n;i++){
        cin >> a[i];
    }
    int now = 0;
    sort(a, a+n);
    int cost = 0, height=0;
    int del = 0;
    while(1){
        //int _;cin >> _;
        if (now == n-1){
            break;
        }
        while(1){
            cost = (now-del+1)*(a[now+1]-a[now]);
            height = a[now]-a[del];
            //cout << "cost:"<<left<<endl;
            if (left-cost>=0){
                left-=cost;
                now++;  
            }else{
                break;
            }
        }

        //remove del
        int get = height;
        //try new;
        cost = (now-del)*(a[now+1]-a[now]);
        if (left+get-cost>=0){
            del++;
            left+=get;
            left-=cost;
            now++;
            height = a[now]-a[del];
            //cout << "deleted"<<left<<endl;
        }else{
            break;
        }
        
    }
    cout << now-del+1;
}