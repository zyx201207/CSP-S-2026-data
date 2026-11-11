#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
usnig namespace std;
struct one{
    stack a;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    long long c[a];

    for(int i=0;i<a;i++){
        scanf("%d",c[i]);
    }
    sort(c,c+a);
    for(int i=0;i<a;i++){
        c[i]-=c[0];
    }
    long long max=1;
    for(int i=1;i<a;i++){
        int jf=0;
        int gs=0;
        for(int j=i;j>+0;j--){
            jf+=c[i]-c[j];
            if(jf>b)
                break;
            gs++;
        }
        if(gs>max)
           max=js;
        }
    printf("%d",max);
    return 0;
}