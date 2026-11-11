#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 +5;

long long n,m,tmpm,Left=1,Right;
long long arr[maxn],ans[maxn],answer=1;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin.tie(0);
    
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr+1,arr+n+1);

    ans[0] = 0;
    unsigned long long fullCost = 0;
    for(long long Right = 1; Right <= n; Right++){
        fullCost += ans[Right-1]*(arr[Right]-arr[Right-1]);
        if(fullCost <= m) {ans[Right]=ans[Right-1]+1; continue;}
        long long tot=0;
        long long ReduceCost;
        while(Left < Right && fullCost>m){
            ReduceCost = arr[Right]-arr[Left++];
            fullCost-=ReduceCost;
            tot++;
        }
        ans[Right]=ans[Right-1]+1-tot;
    }

    for(long long i=1; i <= n; i++){answer = max(answer,ans[i]);}


    cout << answer << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}