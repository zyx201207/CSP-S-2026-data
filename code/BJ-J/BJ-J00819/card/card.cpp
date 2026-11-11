#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],z[500005];
bool b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[j]=false;
        }
        int cnt=0;
        for(int j=i;j<=n;i++){
            if(b[a[j]]==false){
                b[a[j]]=true;
                cnt++;
                z[cnt]=a[j];
            }
            else{
                int u=cnt;
                for(int k=u;k>=1;k--){
                    if(z[k]==a[j]){
                        break;
                    }
                    b[z[k]]=false;
                    cnt--;
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(b[j]){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],z[500005];
bool b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[j]=false;
        }
        int cnt=0;
        for(int j=i;j<=n;j++){
            if(b[a[j]]==false){
                cnt++;
                b[a[j]]==true;
                z[cnt]=a[j];
            }
            else{
                for(int k=cnt;k>=1;k--){
                    if(z[k]==a[j]){
                        break;
                    }
                    b[z[k]]=false;
                    cnt--;
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(b[j]){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],z[500005];
bool b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=0;
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            b[j]=false;
        }
        int cnt=0;
        for(int j=n;j>=i;j--){
            if(b[a[j]]==false){
                cnt++;
                b[a[j]]=true;
                z[cnt]=a[j];
            }
            else{
                for(int k=cnt;k>=1;k--){
                    if(z[k]==a[j]){
                        break;
                    }
                    b[z[k]]=false;
                    cnt--;
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(b[j]){
                ans[j]++;
            }
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],z[500005];
bool b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[j]=false;
        }
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(b[a[j]]==false){
                cnt++;
                b[a[j]]=true;
                z[cnt]=a[j];
            }
            else{
                for(int k=cnt;k>=1;k--){
                    if(z[k]==a[j]){
                        break;
                    }
                    b[z[k]]=false;
                    cnt--;
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(b[j]){
                ans[j]++;
            }
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
*/
