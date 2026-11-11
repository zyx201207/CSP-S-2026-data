#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200100];
long long s;
char c[200100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        if(c[i]==c[i-1]){
            a[i-1]+=a[i];
            i--;
            n--;
        }
    }
    int i=1,j=n;
    while(i<j){
        if(c[i]!=c[j]){
            s+=min(a[i],a[j]);
        }
        long long z=min(a[i],a[j]);
        a[i]-=z;
        a[j]-=z;
        if(a[i]==0){
            i++;
        }
        if(a[j]==0){
            j--;
        }
    }
    cout << s;
    return 0;
}
