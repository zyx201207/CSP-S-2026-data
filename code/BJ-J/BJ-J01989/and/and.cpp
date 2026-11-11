#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int ans[200000];
int a[200000];
int maxn = -1;
int n,m;
void search(int x,int j){

    if(x==m){
        int nn = ans[0];
        for(int i = 1;i<m;i++){
            nn = (nn&ans[i]);
        }
        maxn = max(maxn,nn);
        return;
    }
    if(j+1<n){
        for(int i = j+1;i<n;i++){
            ans[x] = a[i];
            search(x+1,i);
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i =0 ;i<n;i++){
        cin >> a[i];
    }
    search(0,-1);
    cout << maxn;

    return 0;