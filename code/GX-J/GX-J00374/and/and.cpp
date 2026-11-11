#include<bits/stdc++.h>
using namespace std;
long long n,m;
string s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int num=0;
    for(int i=0;i<n;i++){
        num+=i;
    }
    int number=0,x=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((s[i] and s[j])>x){
                x=s[i] and s[j];
            }
        }
    }
    cout<<x;
}
