#include<bits/stdc++.h>
using namespace std;
int a[10005];
vector<int> pz;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    srand(time(0));
    int x;
    for(int i=0;i<m;i++){
        cout<<rand()%x+1;
    }
}
