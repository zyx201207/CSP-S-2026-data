#include<bits/stdc++.h>
using namespace std;
int ans[4];
int main(){
    freopen("travel.int","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a,b;
    string ar,br;
    cin>>a>>ar>>b>>br;
    if(a==b){
        ans[0]=1;
        int n=0,m=0;
        char c,d;
        for(int i=0;i<3;i++){
            if(ar[i]>='0'&&ar[i]<='9'){
                n=n*10+(ar[i]-'0');
            }else{
                if(ar[i] >= 'A' && ar[i] <= 'Z')c=ar[i];
            }
            if(br[i]>='0'&&br[i]<='9'){
                m=m*10+(br[i]-'0');
            }else{
                if(br[i] >= 'A' && br[i] <= 'Z'){
                    d=br[i];
                }
            }
        }
        if(n==m){
            ans[1]=1;
            if((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C')){
                ans[2]=1;
                if(max(c,d)-min(c,d)==1) ans[3]=1;
            }else{
                if((c=='D'||c=='F')&&(d=='D'||d=='F')) ans[2]=1,ans[3]=1;
            }
        }
    }else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<4;i++) cout<<ans[i];
    return 0;
}
