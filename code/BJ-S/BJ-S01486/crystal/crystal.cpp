#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long a[500005];
long long les[500005];

bool cmp(int x,int y){
    return x<y;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    les[1]=0;
    for(int i=2;i<=n;i++){
        les[i]=a[i]-a[1];
    }

    long long maxl=-1;
    for(int i=2;i<=n;i++){
        long long sum=0;
        long long newlong=1;
        for(int j=i-1;j>=1;j--){
            if(sum+les[i]-les[j]<=m){
                sum+=les[i]-les[j];
                newlong++;
            }else{
                break;
            }
        }
        maxl=max(maxl,newlong);
    }
    printf("%d",maxl);
    fclose(stdin);
    fclose(stdout);

    return 0;
}
