#include<bits/stdc++.h>

using namespace std;

int x[200010][5],ans=0;

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        string str0;
        cin>>x[i][0];
        cin>>str0;
        x[i][1]=str0[0]-'a'+1;
    }
    int j=n;
    for(int i=1; i<=n; i++){
        while(j>=1){
            if(x[j][0]<=x[i][0]&&x[j][1]!=x[i][1]){
                ans+=x[j][0];
                x[i][0]-=x[j][0];
                x[j][0]=0;
                j--;
            }
            else if(x[j][0]<=x[i][0]&&x[j][1]==x[i][1]){
                x[i][0]-=x[j][0];
                x[j][0]=0;
                j--;
            }
            else if(x[j][0]>=x[i][0]&&x[j][1]!=x[i][1]){
                ans+=x[i][0];
                x[j][0]-=x[i][0];
                x[i][0]=0;
            }
            else if(x[j][0]>=x[i][0]&&x[j][1]==x[i][1]){
                x[j][0]-=x[i][0];
                x[i][0]=0;
            }
            if(x[i][0]==0){
                break;
            }
        }
        if(i==j){
            break;
        }
    }
    cout<<ans;

    return 0;
}
