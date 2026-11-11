//GZ-J00496 遵义市第十六中学 张旋彬
#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    long long n,m,cnt=0,a[100001];
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    for(int l=1;l<=m;l++){
        for(int i=0;i<n;i++){
            for(int j=i+1;i<n-1;j++){
                if(a[i]==a[j]){
                    for(int k=i;k<j;k++){
                        a[k]=0;
                    }
                }
            }
            if(a[i]==l){
                cnt++;
            }
        }
        cout<<cnt<<' ';
    }
    }
    return 0;
}
