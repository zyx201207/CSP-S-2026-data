#include <bits/stdc++.h>
using namespace std;

int n,m = 0,sum = 0;
int a[2000005];
char c[1000000009];
char s[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        cin >> c[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= a[i];j++){
            s[++m] = c[i];
        }
    }
    int x = m / 2;
    for(int i = 1,j = m;i <= x && j >= x;i++,j--){
        if(s[i] != s[j]){
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}
