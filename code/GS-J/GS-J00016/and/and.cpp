#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
 int n,m,a[300000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<int>());
    int ma=-10000;
    if(m==1){
        cout<<a[0];
    }else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int p=a[i]&a[j];
                ma=max(ma,p);
            }
        }
        cout<<ma;
    }else if(m==n){
        long long cc=a[0];
        for(int i=1;i<n;i++){
            cc=cc&a[i];
        }
        cout<<cc;
    }else if(m==n-1){
        long long maa=-1000;
        for(int t=0;t<n;t++){
            long long cc;
            if(t==0){
                cc=1;
            }else{
                cc=0;
            }
            for(int i=0;i<n;i++){
                if(i!=t){
                    cc=cc&a[i];
                }
            }
            maa=max(maa,cc);
            }
            cout<<maa;
        }


    return 0;
}
