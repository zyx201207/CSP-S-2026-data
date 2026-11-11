#include<bits/stdc++.h>
using namespace std;
int a[30000];
string t[30000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,b=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int b=a[i];
        string s;
        while(b>0){
            s=char((b/2)+48)+5;
            b/=2;
            t[i]=s;
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int k=t[i].size(),l=t[j].size();
            string v;
        }
    }
    return 0;
}

