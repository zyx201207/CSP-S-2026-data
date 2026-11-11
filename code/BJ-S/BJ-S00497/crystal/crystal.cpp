#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long num,maxnum,count_m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        num=0;
        count_m=0;
        for(int j=1;j<=i;j++){
            if((count_m+abs(a[i]-a[j]))<=m){
                count_m+=abs(a[i]-a[j]);
                num++;
            }
        }
        maxnum=max(maxnum,num);
    }
    cout<<maxnum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
