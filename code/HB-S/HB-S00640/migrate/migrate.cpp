#include <bits/stdc++.h>
using namespace std;

struct node{
    long long int position, next;
};

node arr[2000000];

int check(int l, int r){
    int ans = 1;
    int count = 0;
    while(l < r){
        if(arr[l].next == 0){
            return 0;
        }

        if(arr[l].next == 2 && check(l+1, r) == 1){
            
            ans++;
        }
        l += arr[l].next;
        count++;
    }
    return ans;
}



int main(){

    // freopen("subway.in", "r", stdin);
    // freopen("subway.out", "w", stdout);
    
    int c, t;
    cin >> c >> t;
    while(t--){
        long long int n, d;
        
        cin >> n >> d;
        for(int i = 0; i < n; i++){
            cin >> arr[i].position;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j+i < n && arr[j+i].position - arr[i].position <= d; j++){
                arr[i].next = j;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+2; j < n; j++){
                if(check(i, j) == 2){
                    ans++;
                }
                
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}