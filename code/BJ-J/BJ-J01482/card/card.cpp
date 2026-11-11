#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int d,c;
    cin>>d>>c;
    for(int i=1;i<=d;i++){
        cin>>a[i];
    }
    int num=1;
    int ans=0;
    for(int i=1;i<=d;i++){
        ans=0;
        for(int j=i;j<=d;j++){
            b[num]=a[j];
            num++;
            for(int k=1;k<num;k++){
                if(b[k]==b[num]){
                    num-=num-k;
                    for(int l=k;l<=num;l++){
                        b[l]=0;
                    }
                    b[k]=b[num];
                    b[num]=0;
                }

            }
        }
        for(int j=1;j<=num;j++){
            if(b[j]==i){
                ans++;
            }
        }
        cout<<ans<<' ';
    }
    return 0;
}
