#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,sum=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        long long ans=n;
        while(ans--){
            for(int j=2;j<=a[i];j++){
                if(a[i]==a[i-1]){
                    for(int a=a[i-1];a<a[i];a++){
                            if(a[i]==1){
                                    sum++;


                            }

                    }



                }
            }

        }
        cout << sum;
        sum=0;
    }




    return 0;
}
