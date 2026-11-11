#include<bits/stdc++.h>
using namespace std;
char s[100001];
int x[100001];
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> s[i];
    }
    long long ans = 0;
    int sur = n;
    int l = 1 , r = n;
    while(1){
        if(x[l] < x[r]){
            if(s[l] == s[r]) x[r]-=x[l];
            else{
                ans+=x[l];
                x[r]-=x[l];
            }
            l++;
        }
        if(x[l] == x[r]){
           if(s[l] == s[r]) x[r]-=x[l];
            else{
                ans+=x[l];
                x[r]-=x[l];
            } 
            l++ , r--;
        }
        if(x[l] > x[r]){
            if(s[l] == s[r]) x[l]-=x[r];
            else{
                ans+=x[r];
                x[l]-=x[r];
            }
            r--;
        }
        if(l >= r){
            cout << ans;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
}