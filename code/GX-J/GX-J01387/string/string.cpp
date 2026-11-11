#include<bits/stdc++.h>
using namespace std;

long long a,ans,q;
int n;
string s;
char p;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>p;
        for(long long j=0;j<a;j++){
            s+=p;
        }
    }
    for(int i=0;i<(s.size()/2);i++){
        for(int j=s.size()-1;j>(s.size()/2);j--){
            if(i!=j&&s[i]!=s[j]){
                s[j]=s[i];
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
