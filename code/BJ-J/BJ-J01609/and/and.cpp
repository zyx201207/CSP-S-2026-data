#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n,m;
int a[20005];
bool used[20005] = {0};

int search(int deep){
    int x = 0;
    if(deep == 0){
        for(int i = 1;i <= m;i++){
            if(used[i] != 1){
                x = a[i];
            }
        }
        return x;
    }
    for(int i = 1;i <= m;i++){
        if(used[i] != 1){
            used[i] = 1;
            x = max(x&a[i],search(deep-1));
            used[i] = 0;
        }
    }
    return x;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;

    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    cout<<search(m);
    return 0;
}

