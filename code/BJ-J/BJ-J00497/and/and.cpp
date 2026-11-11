#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int jdz(int a){
    if(a<0){
        return a*(-1);
    }
    return a;
}
int sim(int a){
    int mem=a,cnt=0;
    while(mem>0){
        mem/=2;
        cnt++;
    }
    int big=1<<cnt;
    int small=1<<(cnt-1);
    if(big-a>a-small){
        return a-small;
    }
    return big-a;

}
int m,n;
int a[100005];
bool mysort(int a,int b){
    if(a>b)return true;
    return false;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+2,mysort);
    int yu=a[1];
    for(int i=2;i<=m;i++){
        yu=(yu&a[i]);
    }
    cout<<yu;
    return 0;
}
