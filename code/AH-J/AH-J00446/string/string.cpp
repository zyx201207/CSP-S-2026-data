#include<bits/stdc++.h>
using namespace std;
string s,t,hw;
int n,cnt;
long long sum;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cnt>>c;
        while(cnt--) s+=c;
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i]) sum++;
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
