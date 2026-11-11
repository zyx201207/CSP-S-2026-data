#include <bits/stdc++.h>

using namespace std;
int a,b;

int main()
{
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //vector<int> n;
    cin>>a>>b;
    long long g;
    long long n[a];
    for(int i=0;i<a;i++){
        for(int j=0;j<i;j++){
            if(n[i]<n[j]){
                g=n[i];
                n[i]=n[j];
                n[j]=g;
            }

        }
    }
    int v=n[a-1];
    for(int i=a-2;i>a-b-2;i--){
        v=v&&n[i];
        //cout<<n[i]<<endl;
    }
    cout<<v+11;
    return 0;
}
