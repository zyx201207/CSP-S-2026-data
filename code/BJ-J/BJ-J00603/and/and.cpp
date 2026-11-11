#include<bits/stdc++.h>
using namespace std;
int a[200000];
int p[200000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int ans;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < m;i++){
        p[i] = i;
    }
    int ls;
    int j;
    while(true){
        ls = a[p[0]];
        for(int i = 1;i < m;i++){
            ls &= a[p[i]];
        }
        ans = max(ans,ls);
        j = 1;
        while(!(p[m-j] < n-j)){
            j++;
            if(j > m) break;
        }
        if(j > m) break;
        p[m-j]++;
        while(--j){
            p[m-j] = p[m-j-1]+1;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
