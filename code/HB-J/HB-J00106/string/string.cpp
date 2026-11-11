#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m,cnt=0,mb,len;
    string s;
    cin>>n;



    for(int i=0;i<n;i++){
        int lss;
        string ls;
        cin>>lss>>ls;
        for(int j=0;j<lss;j++)
        {

            s+=ls;
        }
    }
    len=s.size();
    if(n%2==0){
        m=len/2;
    }
    else{
        m=len/2+1;
    }
    mb=len-1;
    //cout<<s<<endl;

    for(int i=0;i<m;i++){
        if(s[mb]!=s[i]){
            cnt++;
        }
        //cout<<s[mb]<<" "<<s[i]<<endl;
        mb--;
    }

    cout<<cnt;
    return 0;
}
