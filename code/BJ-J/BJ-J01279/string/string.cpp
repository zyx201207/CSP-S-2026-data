#include<bits/stdc++.h>
using namespace std;
int n,cnt = 0,sum;
int a[200005];
char b[2001000];

char c[200005];
int main(){
    freopen("string.in","r","stdin");
    freopen("string.out","w","stdout");
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d%c",&a[i],&c[i]);
        for(int j = 1;j <= a[i];j++){
            sum++;
            b[sum] = c[i];
        }


    }
    int l = 1,r = n;
    while(l < r){
        if(b[l] != b[r]){
            cnt++;

        }
    }
    printf("%d",cnt);
    return 0;


    
}
