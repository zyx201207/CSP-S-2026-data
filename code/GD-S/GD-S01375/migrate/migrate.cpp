#include<bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;
const int N = 2000010;
int ans[N],arr[N];
int getin(){
    int flag = 1,ans=0;
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
void print(int x,bool flag=1){
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
void dfs(int x){
    ans[x]++;
    for(int i=x+1;i<=n;i++)
}
int main(){
     freopen("migrate.in","r",stdin);
     freopen("migrate.out","w",stdout);
    int c=getin(),t=getin();
    while(t--){
        int n=getin(),d=getin();
        for(int i=1;i<=n;i++) arr[i] = getin();
        dfs(1);
    }

     fclose(stdin);
     fclose(stdout);
    return 0;
}
