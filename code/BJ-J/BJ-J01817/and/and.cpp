#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
int arr[200000];
int max_and = 0;
void dfs(int i, int k, int num){
    if(k==0){
        if(num > max_and) max_and = num;
        return ;
    }
    for(int j=i;j<n-k+1;++j){
        dfs(j+1,k-1,num&arr[j]);
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    dfs(0,m,-1);
    cout << max_and;

    return 0;
}
