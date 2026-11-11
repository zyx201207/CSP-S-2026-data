#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m,a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(m==1){
        int maxn=INT_MIN;
        for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
        printf("%d\n",maxn);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }else if(m==n){
        int sun=0;
        for(int i=1;i<=n-1;i++){
            sun+=a[i]&a[i+1];
        }
        printf("%d\n",sun);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }else if(m==2){
        int maxn=INT_MIN;
        cout<<maxn<<"\t";
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn<<"\n";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    int cnt=a[1]&a[2];
    for(int i=3;i<=m;i++){
        cnt=cnt&a[i];
    }
    cout<<cnt<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
