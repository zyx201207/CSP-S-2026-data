#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a;
    cin>>a;
    long long i[a];
    for(int j=0;j<a;j++){
        cin>>i[j];
    }
    cout<<i[a-1];
    fclose(stdin);
    fclose(stdout);

    return 0;
}
