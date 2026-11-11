#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n;
    cin>>n;
    int a[n],lj=0,sum=0,lja=0;
    char c[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c[i];
        lj+=a[i];
    }
    char A[lj];
    for(int i=0;i<n;i++){
        for(int j=lja;j<lja+a[i];j++){
            A[j]=c[i];
        }
        lja+=a[i];
    }

    lj/=2;
    char a1[lj],a2[lj];
    int f=0;
    for(int i=0;i<n;i++){
        if(c[i]==c[i+1]){
            f++;
        }
    }

    if(f==n-1){
        cout<<"0";
        return 0;
    }
    else{
        for(int i=0;i<lj;i++){
            a1[i]=A[i];
        }
        for(int i=0;i<lj;i++){
            a2[i]=A[lj*2-(lj+i)];
        }
        for(int i=0;i<lj*2;i++){
            if(a1[i]==a2[i]){
                sum++;
            }
        }
        cout<<sum;
    }
    return 0;
}
