#include<bits/stdc++.h>
using namespace std;

string S1,S2;
char ch,tp;
long long L,n,a[200005],tmp,ans=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>tmp>>ch;
        S1.append(tmp,ch);
    }
    tmp=S1.size();

    for(int i=tmp-1;i>=0;i--){
         S2+=S1[i];
    }
    tmp/=2;
    for(int i=0;i<tmp;i++){
        if(S2[i]!=S1[i]&&S2[i]>='a'&&S2[i]<='z'){
            //cerr<<S2[i]<<" "<<S1[i]<<endl;
            ans++;
        }
    }

    cout<<ans<<endl;
    return 0;
}
/*4
3 a
3 b
3 c
3 a
*/
