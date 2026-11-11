#include<iostream>
using namespace std;

int a[200010],ans[200010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >>n >> m;
    for(int i = 1;i <= n;i++){
        cin >>a[i];
        ans[a[i]]++;
        if(a[i] != a[i - 1]) ans[i-1] += n-i+1;
    }
    for(int i = 1;i <= m;i++) cout <<ans[i]<<" ";
    return 0;
}
