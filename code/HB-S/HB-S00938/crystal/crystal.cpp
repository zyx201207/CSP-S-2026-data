#include<bits/stdc++.h>
using namespace std;
int m;
int n;
int ans = 1;
int main ()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    int a[n+10] ;
    for(int i =0 ;i < n;i++){
        cin >> a[i];
    }
    /*
    0 1
    1 2
    2 4
    3 8
    4 9
    */
    int b[a[n-1]][3];
    for(int i =0 ;i < n;i++){
        b[a[i]][1]+=1;
    }
    /*
    1 1 1
    2 1 1
    4 1 1
    8 1 1
    9 1 1
    */
    double k = n;
    int mid = ceil(k/2);
    //mid==3
    if(b[a[mid]][1] > 1){
        for(int i = 1;i<(n-mid);i++){
            if(a[i+mid]==a[mid]){
                ans++;
            }else
                break;
        }

    }
    int l =1;
    while(m>0){
        int d = a[mid]- a[mid-l];
        if(d <= m){
            m-=d;
            ans++;
        }else {
            break;
        }
        l++;

    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
