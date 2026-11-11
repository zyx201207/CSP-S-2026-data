#include<bits/stdc++.h>
using namespace std;
int sum[1000086];
int main(){
    int n,m;
    int a[1000005];
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        int b[1000086];
        for(int j=i;j<n;j++){
            for(int x=0;x<j;x++){
                if(b[x]==b[j] and b[x]!=-1){
                    for(int y=x;y<j;y++){
                        b[y]=-1;
                    }
                }

            }
            b[j]=a[i];
        }
        for(int j=0;j<n;j++){
            if(b[j]!=0 and b[j] !=-1 ){
                sum[b[j]]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
       cout << sum[i] << " ";
    }

    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    return 0;
}
