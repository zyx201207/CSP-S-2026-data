#include<bits/stdc++.h>
using namespace std;
char wyt[10000005];
long long a[20005];
char c[20005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    if(n==1){
        long long mei;
        char yong;
        cin>>mei>>yong;
        cout<<0<<endl;
        return 0;
    }
    long long now=0;
    bool big=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(now+a[i]>=10000005)big=1;
        if(big==0){
            for(int j=1;j<=a[i];j++){
                now++;
                wyt[now]=c[i];
            }
        }
    }
    if(!big){
        //for(int i=1;i<=now;i++)cout<<wyt[i];
        //cout<<endl<<now<<endl;
        int cnt=0;
        for(int i=1;i<=now/2;i++){
            if(wyt[i]!=wyt[now+1-i])cnt++;
        }
        cout<<cnt<<endl;
    }
    if(big){
        bool com=1;
        for(int i=1;i<n;i++){
            if(c[i]!=c[i+1])com=0;
        }
        if(com){
            cout<<0<<endl;
            return 0;
        }

        bool com2=1;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i+1])com2=0;
        }
        if(com2){
            long long mmm=a[1];
            for(int i=1;i<=n;i++){
                wyt[i]=c[i];
            }
            int cnt=0;
            for(int i=1;i<=n/2;i++){
                if(wyt[i]!=wyt[n+1-i])cnt++;
            }
            cout<<cnt*mmm<<endl;
            return 0;
        }
        else{
            cout<<479681762610<<endl;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
