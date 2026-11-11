#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a,rp,len;
char c,s[N];
main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>c;
        for(int i=len;i<len+a;i++) s[i]=c;
        len+=a;
        //for(int i=0;i<len+a;i++) cout<<s[i]<<" ";
        //cout<<endl<<n<<endl;
    }
    int i=0,j=len-1;
    while(i!=j&&(j-i)>1){
        if(s[i]!=s[j]) rp++;
        i++;
        j--;
    }
    cout<<rp;
    return 0;
}