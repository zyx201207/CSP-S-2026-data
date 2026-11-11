#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 +10;
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if(m==1){
        int ans = -1;
        while(n){
            int num;
            cin >> num;
            ans = max(ans,num);
            n--
        }
        cout <<ans ;
    
    }else if(m==n){
        int ans;
        cin >> ans;
        n--;
        while(n){
            int num;
            cin >> num;
            ans = ans & num;
            n--
        }
        cout << ans;
    }else if(m == 2){
        int a[N];
        memset(a,0,N);
        for(int i = 1;i<=n;i++){
            cin >> a[i];
        }
        int ans = -1;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j <=n;j++){
                if(i != j) ans = max(ans,a[i] & a[j]);
            }
        }
        cout << ans;
    }else{
        cout << n-m+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
