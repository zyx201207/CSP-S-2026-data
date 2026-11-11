#include<bits/stdc++.h>
using namespace std;
pair<long long,char> s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        s[i].first=a;s[i].second=c;
    }
    int fir=1,las=n;
    unsigned long long all=0;
    while(fir<las){
        if(s[fir].second!=s[las].second){all+=min(s[fir].first,s[las].first);}
        if(s[fir].first>=s[las].first){
            s[fir].first-=s[las].first;
            if(s[fir].first<=0){fir++;}
            las--;
        }
        else{
            s[las].first-=s[fir].first;
            fir++;
        }
    }
    cout<<all;
    return 0;
}
