#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int c[a],d[a],e[a]={},s;
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    for(int i=0;i<a;i++){
        s=0;
        for(int j=i;j<a;j++){
            d[j]=c[j];
            for(int k=i;k<j;k++){
                if(d[k]==d[j]){
                    s+=j-k;
                }
            }
        }
        for(int j=s;j<a;j++){
            e[j]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<e[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
