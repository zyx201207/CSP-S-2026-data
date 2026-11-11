#include<iostream>
#include<fstream>
using namespace std;
long long int a[200005],lT[26],rT[26],L,mid,lc,rc,mdf,ans;
char c[200005],dd;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin("string.in");
    ofstream cout("string.out");
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
    }
    mid=L/2;
    bool f=L%2==0;
    if(f)mid++;
    int t=1;
    for(long long int e=0;e<=mid-1;){
        if(e+a[t+1]>mid-1){
            dd=c[t];
            lc=mid-1-e+(f?1:0);
            rc=e+a[t]-mid;
            mdf=t;
            break;
        }
        else e+=a[t++];
    }
    lT[dd-'a']+=lc;
    rT[dd-'a']+=rc;
    for(long long int i=1;i<mdf;i++)lT[c[i]-'a']+=a[i];
    for(long long int i=mdf+1;i<=n;i++)rT[c[i]-'a']+=a[i];
    for(int i=0;i<26;i++){
        ans+=abs(lT[i]-rT[i]);
    }
    cout<<ans/2;
}
