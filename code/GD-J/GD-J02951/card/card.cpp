#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n+1]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    queue<int> q;
    for(int c=1;c<=n;c++){
        int last=c;
        for(int i=1;i<=n;i++){

            for(int j=i;j>=last;j--){
                if(a[j] == a[i]){
                    last=j;
                    break;
                }
            }


        }
        cout<<n-last+1<<" ";

    }


}
