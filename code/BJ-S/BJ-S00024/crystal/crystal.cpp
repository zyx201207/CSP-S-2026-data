#include<bits/stdc++.h>
#define ll long long
using namespace std;

int getll(){
    int f = 1;
    int sum = 0;
    int c = getchar();
    while(c<'0' || c>'9'){
        if(c == '-'){
            f = -1;
        }
        c = getchar();
    }
    while(c<='9' && c>='0'){
        sum = sum * 10 + c - '0';
        c = getchar();
    }
    if(c != EOF){
        ungetc(c,stdin);
    }
    return sum;
}

struct data{
    ll w;
    ll z;
};

ll l[500005];
ll len;
ll nl;
data b[500005];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n = getll();
    ll m = getll();
    for(ll i=0;i<n;i++){
        l[i] = getll();
        b[i].w = i;
    }
    len = n;
    ll i;
    for(i=0;i<n;i++){
        //printf("i=%d\n", i);
        nl = 0;
        for(ll j=0;j<len;j++){
            if(i==b[j].w+1){
                continue;
            }
            if(l[b[j].w]-l[b[j].w-i]+b[j].z <= m){
                b[nl] = {b[j].w, l[b[j].w]-l[b[j].w-i]+b[j].z};
                nl++;
            }
        }
    //for(ll j=0;j<nl;j++){
    //    printf("    %d", l[b[j].w]);
    //}
    //printf("\n");
        if(nl == 0){
            break;
        }
        len = nl;
    }
    printf("%lld ", i);
    //printf("%lld", b[0].w+1);


    fclose(stdin);
    fclose(stdout);
    return 0;
}
