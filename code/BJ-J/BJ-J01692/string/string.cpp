#include<iostream>
#include<string>
using namespace std;
string s;
int n,len;
int ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        string c;
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s+=c;
            len++;
        }
    }
    //cout<<s<<endl;
    for(int i=0;i*2<len;i++){
        //cout<<s[i]<<" "<<s[len-i-1]<<endl;
        if(s[i]!=s[len-i-1])
            ans++;

    }
    cout<<ans;
    return 0;
}
