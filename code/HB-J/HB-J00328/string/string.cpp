#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        while(a--) s=s+c;
    }
    int len1,len2;
    if(s.size()%2==1) len1=len2=(s.size()-1)/2;
    else len1=(s.size()-2)/2,len2=s.size()/2;
    long long cnt=0;
    for(int i=0,j=s.size()-1;i<=len1,j>=len2;i++,j--){
        if(s[i]!=s[j]) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
