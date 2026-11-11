#include<bits/stdc++.h>
using namespace std;
int island[1000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int abcdefg,t;
    cin>>abcdefg>>t;
    for(int i=1;i<=t;i++){
        int n,d,sum=0;
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>island[i];
        }
        for(int j=1;j<=n;j++){
            for(int k=i+3;k<=n;k++){
                int num=0;
                for(int l=j+1;l<k;l++){
                    if(island[l]-island[j]<=d&&island[k]-island[l]<=d){
                        num++;
                    }
                }
                if(num==2){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
