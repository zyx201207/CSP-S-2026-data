#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char k[200005];
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;//2e5
    for(int i = 1;i <= n;i++){
        cin>>a[i];//1e9
        cin>>k[i];
    }
    long long len = n / 2;
    int i = 1,j = n;
    long long s = 0;
    while(i < j){
        if(k[i] != k[j]){
            s += min(a[i],a[j]);
            a[i]-= min(a[i],a[j]),a[j]-= min(a[i],a[j]);
            if(a[i] == 0){
                i++;
            }
            if(a[j] == 0){
                j--;
            }
        }else{
            a[i] -= min(a[i],a[j]),a[j] -= min(a[i],a[j]);
            if(a[i] == 0){
                i++;
            }
            if(a[j] == 0){
                j--;
            }
        }
    }
    cout<<s;
    return 0;
}