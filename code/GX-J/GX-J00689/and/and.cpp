#include<iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b;
    char c[10000000];
    int maxn=-1;
    for(int i=1;i<=a;i++){
        cin>>c[i];
        maxn=c[i]&c[i+1];
        if(maxn<c[i]&c[i+1]){
            maxn=c[i]&c[i+1];
        }
    }
    cout<<maxn;
    return 0;
}
