#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s[1000001],h[1000001];
    int n;
    cin>>n;
    int x=0,g=0;
    for(int i=0;i<n;i++){
        int a;
        char b;
        cin>>a>>b;
        g+=a;
        for(int j=0;j<a;j++){
            s[x]=b;
            x++;
        }
    }
    int c=0;
    for(int i=g-1;i>=0;i--){
        h[c]=s[i];
        c++;
    }
    if(h==s){
        cout<<"0"<<endl;
        return 0;
    }
    int cnt=0;
    for(int i=g/2;i>=0;i--)
    {
        h[i]=s[i];
    }
    for(int i=0;i<g;i++){
        if(h[i]!=s[i]&&h[i]!=0&&s[i]!=0) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
