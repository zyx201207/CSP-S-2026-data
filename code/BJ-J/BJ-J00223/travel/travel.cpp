#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1,a2,b2;char c1,c2;
    scanf("%d %d%c %d %d%c",&a1,&a2,&c1,&b1,&b2,&c2);
    if(a1!=b1)printf("0000");
    else{
        if(a2!=b2)printf("1000");
        else{
            if((c1=='D'||c1=='F')^(c2=='D'||c2=='F'))printf("1100");
            else if(c1=='A'&&c2=='C')printf("1110");
            else printf("1111");
        }
    }
    return 0;
}
