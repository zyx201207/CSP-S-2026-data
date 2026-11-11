#include<bits/stdc++.h>
using namespace std;
string s;
struct is{
    int a;
    string c;
}b;
long long n,l,cnt;
int main(){
    //freopen("string1.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    //cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cin>>b.a>>b.c;
        //cout<<b.a<<" "<<b.c<<endl;
        for(int j=l;j<b.a+l;j++){
            s[j]=b.c[0];
            //cout<<s[j];
        }
        //cout<<endl;
        l+=b.a;
    }
    //cout<<l<<endl;
    //for(int i=0;i<=l;i++) cout<<s[i]<<" ";
    //cout<<endl;
    while(1){
        int q=0;
        for(int i=0;i<l/2;i++){
            if(s[i]!=s[l-1-i]){
                q=1;
            }
        }
        if(q==0){
            cout<<cnt;
            return 0;
        }
        s[l-1-cnt]=s[cnt];
        cnt++;
    }
    return 0;
}
