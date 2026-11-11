#include<bits/stdc++.h>
using namespace std;
struct fh{
    char f;
    string st,en;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,cnt=0;
    char s;

    cin>>n;
    if(n<=10){
        string c;
        for(int i=1;i<=n;i++){
            cin>>a>>s;
            for(int j=1;j<=a;j++){
                c+=s;
            }
        }//aabbc
        for(int i=0;i<c.size()/2;i++){
            if(c[i]!=c[c.size()-1-i])cnt++;
        }
        cout<<cnt;
        return 0;
    }/*else {
        string c;
        long long sum;
        for(int i=1;i<=n;i++){
            cin>>a>>s;
            c+=s;
            sum+=a;
        }
        long long mid=sum/2;
    }*/


    return 0;
}

