#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char ans[MAXN]={};
    int n;
    cin >> n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin >> a >> c;
        for(int j=cnt;j<cnt+a;j++){
            ans[j]=c;
        }
        cnt+=a;
    }
    int x=(cnt+1)/2;
    int digit=0;
    for(int i=0;i<x;i++){
        int j=cnt-1-i;
        if(ans[i]!=ans[j]){
            ans[j]=ans[i];
            digit++;
        }
    }
    cout << digit;
    return 0;
}
