#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
long long ans;
char c[maxn];
int shu[maxn];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>shu[i]>>c[i];
    for(int i = 1, j = n; i < j;){
        if(c[i] == c[j]){
            if(shu[i] > shu[j]){
                shu[i] -= shu[j];
                j--;
            }else if(shu[i] < shu[j]){
                shu[j] -= shu[i];
                i++;
            }else{
                i++;j--;
            }
        }else{
            if(shu[i] > shu[j]){
                ans += shu[i] - shu[j];
                shu[i] -= shu[j];
                j--;
            }else if(shu[i] < shu[j]){
                ans += shu[j] - shu[i];
                shu[j] -= shu[i];
                i++;
            }else{
                ans += shu[i];
                i++;j--;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}