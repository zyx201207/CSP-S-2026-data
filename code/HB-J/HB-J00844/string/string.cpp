#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cmp,d=0;
    char a[200005]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        int s;
        char st;
        cin>>s>>st;
        for(int j=d;j<d+s;j++){
            a[j]=st;
        }
        d+=s;
    }
    int b=strlen(a);
    for(int i=0;i<b;){
        for(int j=b-1;j>=0;){
            if(a[i]!=a[j]){
                cmp++;
            }
            i++;
            j--;
        }
    }
    cout<<cmp/2;
    return 0;
}
