#include<bits/stdc++.h>
using namespace std;
queue<long long>q;
long long n,m,a[500005];
long long bo[300005];
struct node{
    long long flag;
    bool b;
}arr[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        q.push(a[i]);
    }
    for(int i=1;i<=n;i++){
        memset(arr,0,sizeof arr);
        for(int j=n;j>=i;j--){
            if(arr[a[j]].b==1){
                bo[a[j]]++;
                for(int k=j;k<arr[a[j]].flag;k++){
                    bo[a[k]]--;
                    cout<<i<<" "<<k<<endl<<endl;
                }
                arr[a[j]].flag=j;
            }
            else{
                arr[a[j]].b=1,bo[a[j]]++,arr[a[j]].flag=j;
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<bo[i]<<" ";
    }
    return 0;
}