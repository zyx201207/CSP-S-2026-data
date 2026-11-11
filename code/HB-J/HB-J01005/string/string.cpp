#include<bits/stdc++.h>
using namespace std;
long long S1[200005];
char S2[200005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,i=0;
    cin>>n;
    while(n--){
        long long a;
        char s;
        cin >> a >> s;
        S1[i]=a;
        S2[i++]=s;
    }
    int il=0;
    int ir=i-1;
    while(il<ir){
        if(S2[il]!=S2[ir]){
            ans+=min(S1[il],S1[ir]);
        }
        if(S1[il]>S1[ir]){
            S1[il]-=S1[ir--];
        }
        else if(S1[il]==S1[ir]){
            il++;
            ir--;
        }
        else{
            S1[ir]-=S1[il++];
        }
    }
    cout<<ans;
    return 0;
}
