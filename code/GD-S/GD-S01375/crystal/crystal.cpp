#include<bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;
const int N = 500010;
ll arr[N];
ll getin(){
    ll flag = 1,ans=0;
    char c = getchar();
    while(!isdigit(c)){
        if(c=='-') flag = -1;
        c = getchar();
    }
    while(isdigit(c)){
        ans *= 10;
        ans += c-'0';
        c = getchar();
    }
    return ans * flag;
}
void print(ll x,bool flag=1){
    if(x<0){
        putchar('-');
        x = -x;
    }
    if(x==0){
        if(flag) putchar('0');
        return ;
    }
    print(x/10,0);
    putchar(x%10+'0');
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n=getin(),m=getin(),ans=0;
    for(int i=1;i<=n;i++) arr[i]=getin();
    sort(arr+1,arr+1+n);
    ll c = arr[2]-arr[1];
    bool flag = true;
    for(int i=3;i<=n;i++){
        if(arr[i]-arr[i-1]!=c){
            flag = false;
            break;
        }
    }
    if(flag){
        // deng cha
        int cnt = 1,k=arr[2]-arr[1];
        for(int i=2;i<=n;i++){
            if(m>=(i-1)*k){
                cnt++;
                m -= (i-1)*k;
            }
        }
        print(cnt);
        putchar('\n');
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(arr[i+1]==arr[i]) continue;
        ll tmp = m;
        ll anst = 0;
        for(int j=i-1;j>0;j--){
            if(arr[i]-arr[j]<=tmp){
                tmp-=arr[i]-arr[j];
                anst++;
            }
            ans = max(anst+1,ans);
        }
    }
    print(ans);
    putchar('\n');
    fclose(stdin);
    fclose(stdout);
    return 0;
}
