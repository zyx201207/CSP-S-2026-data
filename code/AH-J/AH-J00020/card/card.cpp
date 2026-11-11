#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
const int N=300005;
int n,m,a[500005],t[N],ans[N];
int t1[N];
bool flag;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t1[a[i]]=i;
        t[a[i]]++;
        if(a[i]<a[i-1]) flag=1;
    }
    if(!flag){
        for(int i=1;i<=m;i++){
            t[i]+=t[i-1];
            ans[i]=t[i];
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++){
        int j=i;
        while(j<=n){
            j=t1[a[j]];
            ans[a[j]]++;
            j++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

