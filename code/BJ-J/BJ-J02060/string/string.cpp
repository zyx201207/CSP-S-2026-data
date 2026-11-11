#include<bits/stdc++.h>
using namespace std;
long long n,a,b[101010101],cnt;
string s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>s1;
        for(int i=1;i<=a;i++){
            s2+=s1;
        }
    }int sss=-1;
    for(int i=0;i<=s2.size();i++){
            sss++;
        b[i]=s2[i]-'a'+1;
    }
    int ssss=0;
    for(int i=sss-1;i>-1;i--){
        if(b[i]!=b[ssss]){
            cnt++;
        }
        ssss++;
    }
    cout<<floor(cnt/2);
    return 0;
}
