#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%d\n",n%3);
    }
    return 0;
}
