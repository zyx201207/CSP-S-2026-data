#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.cpp","r",stdin);
    freopen("and.cpp","w",stdout);
    int n,m,t=0,j=0,minx=123456789,c=0,maxx=0,v=0;
    cin>>n>>m;
    int a[200000]={},s[200000]={},z[200000]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
        t=a[i];
        while(t!=0){
            s[i]+=(t%2)*(j*10);
            j++;
            t=t/2;
        }
    }
    for(int i=0;i<n;i++){
        for(int o=0;o<m;o++){
            minx=min(minx,s[i]);
        }
        while(minx!=0){
            c++;
            minx=minx/10;
        }
        for(int p=0;p<c;p++){
            if(s[p]==s[p+1]==s[p+2]){
               z[i]=(minx%2)*(v*10);
               v++;
            }
        }
    }
    for(int i=0;i<n;i++){
        maxx=max(maxx,z[i]);
    }
    cout<<a[n];
    return 0;
}
