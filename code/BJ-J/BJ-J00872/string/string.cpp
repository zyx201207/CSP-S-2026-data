#include<bits/stdc++.h>
using namespace std;
int x,temp;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1; i<=n; i++){
        cin>>x;
        cin>>a[i];
        if(i>=2 && a[i]!=a[i-1])  temp=1;
    }
    if(temp=0)  cout<<"0";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
