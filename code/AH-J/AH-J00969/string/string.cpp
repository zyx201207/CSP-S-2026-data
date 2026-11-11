#include<bits/stdc++.h>
using namespace std;
int n;
long long mnnum=0;
struct node{
    long long num;
    char c;
};
node a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].num);
        cin>>a[i].c;
    }
    int l=1,r=n;
    while(l<r){
        if(a[l].num>a[r].num){
            if(a[l].c!=a[r].c){
                mnnum+=a[r].num;
            }
            a[l].num=a[l].num-a[r].num;
            r--;
        }else if(a[l].num<a[r].num){
            if(a[l].c!=a[r].c){
                mnnum+=a[l].num;
            }
            a[r].num-=a[l].num;
            l++;
        }else{
            if(a[l].c!=a[r].c){
                mnnum+=a[l].num;
            }
            l++;
            r--;
        }
    }
    printf("%lld",mnnum);
    return 0;
}
