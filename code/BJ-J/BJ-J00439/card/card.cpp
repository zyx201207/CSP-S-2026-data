#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],num[300001];
bool is[300001];
long long read(){
    long long n=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-'){
            f = -1;
        }
        ch = getchar();
    }
    while(ch>='0' && ch<='9'){
        n = n*10+int(ch-'0');
        ch = getchar();
    }
    return n*f;
}
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n = read();
    m = read();
    for(long long i=1;i<=n;i++){
        a[i] = read();
    }
    for(long long i=1;i<=n;i++){
        for(long long i=1;i<=m;i++){
            is[i] = 0;
        }
        stack<long long> s;
        for(long long j=i;j<=n;j++){
            if(is[a[j]]==1){
                while(!s.empty()){
                    if(a[j]==s.top()){
                        break;
                    }
                    is[s.top()] = 0;
                    s.pop();
                }
            }
            else{
                s.push(a[j]);
                is[a[j]] = 1;
            }
        }
        while(!s.empty()){
            num[s.top()]++;
            s.pop();
        }
    }
    for(long long i=1;i<=m;i++){
        printf("%lld ",num[i]);
    }

    return 0;
}
