#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans;
int a[200005];
char c[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i]>>c[i];
    }
    if(n == 1){
        cout<<0;
        return 0;
    }
    int i = 1,j = n;
    while(i < j){
        if(c[i] == c[j]){
            if(a[i] < a[j]){
                a[j] -= a[i];
                i++;
            }
            else if(a[i] > a[j]){
                a[i] -= a[j];
                j--;
            }
            else if(a[i] == a[j]){
                i++;
                j--;
            }
        }
        else if(c[i] != c[j]){
            if(a[i] < a[j]){
                a[j] -= a[i];
                ans += a[i];
                i++;
            }
            else if(a[i] > a[j]){
                a[i] -= a[j];
                ans += a[j];
                j--;
            }
            else if(a[i] == a[j]){
                ans += a[i];
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
