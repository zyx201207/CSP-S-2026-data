#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],p[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool A=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        A=A&(a[i]>=a[i-1]);
    }
    if(A){
        a[n+1]=-114514;
        for(int i=1;i<=n;i++){
            b[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cout<<b[i]<<' ';
        }
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        bool f=1;
        for(int j=i+1;j<=n;j++){
            if(a[j]==a[i]){
                p[i]=j;
                f=0;
                break;
            }

        }
        if(f)p[i]=-1;
    }
    for(int i=1;i<=n;i++){
        int j;
        for(j=i;j<=n;){
            bool f=1;
            int next=p[j];
            if(next!=-1){
                j=next;
            }else{
                b[a[j]]++;
                j++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<' ';
    }
    cout<<endl;



    return 0;
}
