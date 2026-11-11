#include <bits/stdc++.h>
using namespace std;
int n,m;
int p[10001];
int ton[100001];
bool cmp(int a,int b){
    return a>b;
}
int ef(int x,int y);
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    //for(int i=0;i<n;i++){
    //   cout<<p[i];
    //}
    int maox=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int ls=p[i]&p[j];
            //cout<<ls<<endl;
            ton[ls]++;
            maox=max(ls,maox);
        }
    }
    //cout<<endl<<maox<<endl;
    for(int i=0;i<maox;i++){
        if(ton[i]==m){
            cout<<i;
            break;
        }
    }
    //cout<<ef(m,maox);

    return 0;
}
int ef(int x,int y){
    int l=0,r=y;
    int mid=(l+r)/2;
    while(l<=r){
        if(x>ton[mid]){
            r=mid;
        }
        else if(x<ton[mid]){
            l=mid+1;
        }
        else return mid;
        mid=(r+l)/2;
    }
}
