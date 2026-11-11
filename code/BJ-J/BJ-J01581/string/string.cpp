#include<iostream>
#include<cstdio>
using namespace std;

struct cc{
    long long num;
    char s;
}c[100000005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i].num);
        cin>>c[i].s;
        if(c[i].s==c[i-1].s){
            c[i-1].num+=c[i].num;
            i--;
            n--;
        }
    }
    long long sum=0;
    int x=0;
    int y=0;
    for(int i=1;;i++){
        int c1=i,c2=n-i+1-x+y;
        if(c1>=c2){
            break;
        }
        if(c[c1].num!=c[c2].num){
            if(c[c1].s!=c[c2].s){
                sum+=min(c[c1].num,c[c2].num);
                if(c[c1].num>c[c2].num){
                    c[c1].num-=c[c2].num;
                    x++;
                    i--;
                }else{
                    c[c2].num-=c[c1].num;
                    y++;
                }
            }else{
                 if(c[c1].num>c[c2].num){
                    c[c1].num-=c[c2].num;
                    x++;
                    i--;
                }else{
                    c[c2].num-=c[c1].num;
                    y++;
                }
            }
        }else{
            if(c[c1].s!=c[c2].s){
                sum+=c[c1].num;
            }
        }
    }
    printf("%lld",sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
