#include<bits/stdc++.h>
using namespace std;
int m,n,a[100000001],ans[100000001],z[100000001],num,out;
bool flag=false;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        num=0;
        for(int j=i;j<=n;j++){
            flag=false;
            out=a[j];
            for(int k=1;k<=num;k++){
                if(out==z[k]){
                    for(int r=1;r<=n-k;r++){
                        z[k+r]=0;
                    }
                    num=k;
                    flag=true;
                    break;
                }
            }
            if(!flag){
                z[num+1]=a[j];
                num++;
            }
        }
        for(int j=1;j<=num;j++){
            ans[z[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
