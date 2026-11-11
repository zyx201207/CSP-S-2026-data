#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,v;
int t1=0;
int w[100005]={0},a[100005]={0},b[100005]={0};
int sumn(int first1,int finaly1){
    int t=0;
    for(int j=1;j<=m;j++){
        if(first1==j&&first1<=finaly1){
            t=a[j]+w[j];
            first1++;
        }
    }
    return t;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=1;i<m;i++)
        cin>>w[i];
    for(int p=0;p<n;p++){
        cin>>k;
        for(int s=0;s<k;s++){
            cin>>v>>a[v];
        }
    }
    while(q){
            int first,finaly;
        cin>>first>>finaly;
        t1=sumn(first,finaly);
        cout<<t1<<endl;
        q--;
    }

    return 0;
}
