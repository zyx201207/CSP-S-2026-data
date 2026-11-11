#include <bits/stdc++.h>
using namespace std;
int a[500000+10];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    int p=0,s=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if((a[2]-a[0])+(a[2]-a[1])==m){
            a[1]=a[1]+1;
            a[0]=a[0]+1;
            m=m-2;
            p+=1;
           if(m==0) break;
        }
        else if((a[3]-a[0])+(a[3]-a[1])==m){
            a[1]=a[1]+1;
            a[0]=a[0]+1;
            m=m-2;
            p+=1;
           if(m==0) break;
        }
        else if((a[3]-a[1])+(a[3]-a[2])==m){
            a[1]=a[1]+1;
            a[0]=a[0]+1;
            m=m-2;
            p+=1;
           if(m==0) break;
        }

        else if((a[4]-a[0])+(a[4]-a[2])==m){
            a[1]=a[1]+1;
            a[0]=a[0]+1;
            m=m-2;
            p+=1;
           if(m==0) break;
        }
        if(m==0) break;
    }
    cout<<p;
    return 0;
    }

