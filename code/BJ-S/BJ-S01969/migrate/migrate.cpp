#include <iostream>
#include <cstdio>
using namespace std;
int Count(int a[],int n,int t){
    int cnt=0;
    int f=t*2-1;
    for(int i=0;i<n;i++){
        if((i*2-1)>n)break;
        for(int j=i;j<n;j++){
            if(abs(a[j]-a[i])==f)cnt++;
        }
    }
    return cnt;

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int a[500000];
            int n,d;
            cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<Count(a,n,d)<<endl;
    }
    return 0;
}
