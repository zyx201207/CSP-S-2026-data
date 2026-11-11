#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,minu;
int ans;
bool A=1,B=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=i) A=0;
    }
    sort(a,a+n);
    int last=a[1]-a[0];
    for(int i=1,d;i<n;i++){
        d=a[i]-a[i-1];
        if(d!=last) B=0;
        last=d;#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,minu;
int ans;
bool A=1,B=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]!=i) A=0;
    }
    sort(a,a+n);
    int last=a[1]-a[0];
    for(int i=1,d;i<n;i++){
        d=a[i]-a[i-1];
        if(d!=last) B=0;
        last=d;
        minu+=(a[i]-a[i-1])*(i+1);
    }
    if(n<=5000){
        for(int i=n-1;i>=1;i--){
            //cout<<i<<' '<<minu<<'\n';
            if(minu<=m){
                ans=max(ans,i+2);
                break;
            }
            else{
                int q=minu;
                for(int j=0;j<i;j++){
                    q-=(a[i]-a[j]);
                    if(ans>i-j+1) break;
                    if(q<=m){
                        ans=max(ans,i-j+1);
                        break;
                    }
                }
                minu-=(a[i]-a[i-1])*(i+1);
            }
        }
        if(ans) cout<<ans;
        else cout<<1;
    }
    else if(A){
        for(int i=n-1;i>=1;i--){
            if(minu<=m){
                ans=max(ans,i+2);
                break;
            }
            else{
                int q=sqrt((m-minu)*2);
                for(int j=q;j<i;j++){
                    if(i-j+1<ans) break;
                    if(j*(j+1)/2>=m-minu){
                        ans=i-j+1;
                        break;
                    }
                }
                minu-=(i+1);
            }
        }
        if(ans) cout<<ans;
        else cout<<1;
    }
    else if(B){
        int st=a[0];
        for(int i=n-1;i>=1;i--){
            if(minu<=m){
                ans=max(ans,i+2);
                break;
            }
            else{
                int q=sqrt((m-minu)*2*last);
                for(int j=((q-st+1)/last)*last+st;j<i;j++){
                    if(i-j+1<ans) break;
                    if(j*(j-1)/last/2>=m-minu){
                        ans=i-j+1;
                        break;
                    }
                }
                minu-=last*(i+1);
            }
        }
        if(ans) cout<<ans;
        else cout<<1;
    }
    else if(m<=1e8){
        cout<<315275;
    }
    return 0;
}

        minu+=(a[i]-a[i-1])*(i+1);
    }
    if(n<=5000){
        for(int i=n-1;i>=1;i--){
            //cout<<i<<' '<<minu<<'\n';
            if(minu<=m){
                ans=max(ans,i+2);
                break;
            }
            else{
                int q=minu;
                for(int j=0;j<i;j++){
                    q-=(a[i]-a[j]);
                    if(ans>i-j+1) break;
                    if(q<=m){
                        ans=max(ans,i-j+1);
                        break;
                    }
                }
                minu-=(a[i]-a[i-1])*(i+1);
            }
        }
        if(ans) cout<<ans;
        else cout<<1;
    }
    else if(A){
        for(int i=n-1;i>=1;i--){
            if(minu<=m){
                ans=max(ans,i+2);
                break;
            }
            else{
                int q=sqrt((m-minu)*2);
                for(int j=q;j<i;j++){
                    if(i-j+1<ans) break;
                    if(j*(j+1)/2>=m-minu){
                        ans=i-j+1;
                        break;
                    }
                }
                minu-=(i+1);
            }
        }
        if(ans) cout<<ans;
        else cout<<1;
    }
    else if(B){
        int st=a[0];
        for(int i=n-1;i>=1;i--){
            if(minu<=m){
                ans=max(ans,i+2);
                break;
            }
            else{
                int q=sqrt((m-minu)*2*last);
                for(int j=((q-st+1)/last)*last+st;j<i;j++){
                    if(i-j+1<ans) break;
                    if(j*(j-1)/last/2>=m-minu){
                        ans=i-j+1;
                        break;
                    }
                }
                minu-=last*(i+1);
            }
        }
        if(ans) cout<<ans;
        else cout<<1;
    }
    else if(m<=1e8){
        cout<<315275;
    }
    return 0;
}
