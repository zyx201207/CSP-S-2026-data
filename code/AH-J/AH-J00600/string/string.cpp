#include<bits/stdc++.h>
using namespace std;

int n,sum;
int a,b[100005];
char c[100005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a>>c[i];
        b[i]=a;

        for(int i=1;i<=a;i++)
            s+=c[i];
    }
    if(n<=1)
        cout<<0;
    else if(n==2){
        if(c[1]!=c[2]){
            if(b[1]!=b[2])
                cout<<min(b[1],b[2]);
            else
                cout<<b[1];
        }
        else
            cout<<0;
    }
    else{
        sort(b+1,b+n+1);
        cout<<b[1];
    }
    return 0;
}
