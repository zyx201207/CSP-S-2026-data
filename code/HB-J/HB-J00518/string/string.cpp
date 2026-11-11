#include<bits/stdc++.h>
using namespace std;
int n;
int x;
bool d=0;
long long b[199999999];
string a;
long long l[19999999];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
        x=0;
        cin>>n;
        for(int i=1;i<=n;i++){
                cin>>l[i];
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            int v=a[i]-'a';
            for(int j=1;j<=l[i];j++){
                b[x]=v;
                x++;
            }
        }

        int max=0;
        for(int i=0,j=x-1;j!=i;i++,j--){
            if(b[i]!=b[j]){
                max++;
            }
        }
        cout<<max;
        return 0;
}
