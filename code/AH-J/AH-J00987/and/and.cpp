#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;
vector<int>a;
int ans(int n,int m){
    if(m==1){
        int maxn=-1;
        for(int i:a)
            maxn=max(maxn,i);
        return maxn;
    }if(m==n){
        int sum=a.front();
        for(int i=1;i<n;i++)
            sum&=a[i];
        return sum;
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    a.reserve(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d",ans(n,m));
    //fclose(stdin);fclose(stdout);
    return 0;
}
//Trick||Treat!
