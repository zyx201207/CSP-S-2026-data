#include<bits/stdc++.h>
using namespace std;
long long yi=0,er=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    long long c[a];
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    for(int i=0;i<a;i++){
        if(c[i]==1&&c[i+1]!=c[i]&&i!=4){
            yi+=2;
        }else{
            yi++;
        }
        if(c[i]==2&&c[i+1]!=c[i]&&i!=4){
            er+=2;
        }else{
            er++;
        }
        i++;
    }
    cout<<yi<<" "<<er;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
