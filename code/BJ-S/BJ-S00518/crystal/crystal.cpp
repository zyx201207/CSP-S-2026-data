#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,m,a[N],s[N],ans,num,cnt,flag = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    if(n <= 5000){
        for(int i = 1;i <= n;i++) cin >> a[i];
        sort(a+1,a+n+1);
        for(int i = 1;i <= n;i++) s[i] = s[i-1]+a[i];
        for(int i = 1;i <= n;i++){
            for(int j = i;j >= 1;j--){
                cnt += a[i] - a[j];
                if(cnt > m) break;
                num++;
            }
            ans = max(ans,num);
            num = 0;
            cnt = 0;
        }
        cout << ans;
    }
    else{
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            if(a[i] != a[i-1]) flag = 0;
        }
        if(flag){
            cout << min(n,((long long)sqrt(8*m+1)+1)/2);
        }else{
            int k = a[2]-a[1];
            cout << min(n,(long long)((long long)sqrt((k+8*m)/(4*k))+1/2));
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}