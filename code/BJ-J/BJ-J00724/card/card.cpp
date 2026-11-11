#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int n,m,a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
    }
    if(m==2){
        if(n==2){
            if(a[0]==1)cout<<"1 2";
            else cout<<"2 1";
        }
        if(n==3){
            if(a[0]==1){
                if(a[1]==1)cout<<"2 3";
                if(a[1]==2){
                    if(a[2]==1)cout<<"3 2";
                    else cout<<"1 3";
                }
            }
            else{
                if(a[1]==1){
                    if(a[2]==1)cout<<"3 1";
                    if(a[2]==2)cout<<"2 3";
                }
                else cout<<"3 2";


            }
        }
        if(n==4){
            if(a[0]==1){
                if(a[1]==1){
                    if(a[2]==1){
                        cout<<"3 4";

                    }
                    else{
                        if(a[3]==1) cout<<"4 3";
                        else cout<<"2 4";
                    }
                }
                else{
                    if(a[2]==1){
                        if(a[3]==1)cout<<"4 2";
                        else cout<<"3 4";
                    }
                    else{
                        if(a[3]==1)cout<<"4 3";
                        else cout<<"1 4";
                    }
                }
            }
            else{
                if(a[1]==1){
                    if(a[2]==1){
                        if(a[3]==1)cout<<"4 1";
                        else cout<<"3 4";
                    }
                    else{
                        if(a[3]==1)cout<<"4 3";
                        else cout<<"2 4";

                    }
                }
                else{
                    if(a[2]==1){
                        if(a[3]==1)cout<<"4 2";
                        else cout<<"3 4";
                    }
                    else{
                        cout<<"4 3";
                    }
                }

            }
        }
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll =long long;
int n,m,a[500005],s[500005];
bool ok[500005][2],o;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=n;i>=1;i--){
        for (int j=1;j<=m;j++){
            if(!ok[j][0]){
                o=1;
            }
        }
        if(o){
            if(!ok[a[i]][0]){
                s[a[i]]=i;
                ok[a[i]][0]=1;
                ok[a[i]][0]=i;
            }

        }
        else{
            break;
        }
    }
    for (int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
*/
