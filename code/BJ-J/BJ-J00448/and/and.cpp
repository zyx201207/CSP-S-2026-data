#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[200086],a[30][200086],c[30],cc[30];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b+1,b+n+1,cmp);
    for(int i=1;i<=n;i++){
        int j=0;
        while(b[i]!=0){
            c[j]=b[i]%2;
            b[i]/=2;
            j++;
        }
        reverse(c,c);
        for(int k=0;k<=30;k++){
            a[k][i]=c[k];
        }
        for(int i=0;i<=30;i++){
            c[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(m==0){
            break;
        }
        m--;
        for(int j=30;j>=0;j--){
            if(a[j][i-1]==1&&a[j][i]==1){
                cc[j]=1;
            }else{
                cc[j]=0;
            }
        }
    }
    m=0;
    for(int i=0;i<=30;i++){
        if(cc[i]==1){
            m+=pow(2,i);
        }
    }
    cout<<m;
    return 0;
}
