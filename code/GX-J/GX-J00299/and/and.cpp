#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long s[100005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >>m;
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    int maxn=0;
    int a,b;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i]&s[j]>maxn){
                maxn=s[i]&s[j];
                a=i;
                b=j;
            }
        }
    }
    m--;
    int maxn2=0;
    while(m--){
        for(int i=0;i<n;i++){
            if(i!=a&&i!=b){
                if(maxn&s[i]>maxn2){
                    maxn2=maxn&s[i];
                }
            }
        }
    }
    cout << maxn2;
    return 0;
}
