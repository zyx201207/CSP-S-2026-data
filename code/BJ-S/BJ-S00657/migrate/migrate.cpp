#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int a,b;
    int a1,b1;

    int cnt[100] = {0};
    cin>>a>>b;
    int d[100][100];
    for(int i = 0;i<=b+1;i++){
        if(i == 0)continue;
        cin>>a1>>b1;
        for(int j = 0;j<=a1;j++){
            cin>>d[i][j];
            if(d[i][j-1]<b1&&d[i][j]<b1){
                cnt[i]+=1;
            }
        }
    }
    for(int i = 1;i<=b;i++){
        cout<<cnt[i]<<endl;
    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}
