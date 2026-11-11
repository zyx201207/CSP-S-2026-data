#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cout<<rand()%n+1;
    }
    fclose(stdin);
    fclose(stdout);
}
