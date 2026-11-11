#include<bits/stdc++.h>
using namespace std;
long long n,A[200009],a[200009],h[200009],X,hf,ans=0;
char C[200009],c[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i]>>C[i];
        X=max(X,A[i]);
        h[i]=h[i-1]+A[i];
    }
    if(X==1){
        for(int i=1;i<=n/2;i++){
            if(C[i]!=C[n+1-i])ans++;
        }
        cout<<ans;
    }
    else{
        int _1=0,_2=0;
        for(int i=1;i<=n;i++){
            if(h[i]<h[n]/2)a[i]=A[i],c[i]=C[i];
            else if(_1==0&&h[i]>=h[n]/2){
                hf=i;
                _1==1;
                if(h[i]==h[n]/2)a[i]=A[i],c[i]=C[i];
                else a[i]=h[n]/2-h[i-1],c[i]=C[i],_2=1,a[i+1]=h[i]-h[n]/2,c[i+1]=C[i];
            }
            else{
                a[i+_2]=A[i];
                c[i+_2]=C[i];
            }
        }
        int l=1,r=n+_2;
        while(l<=hf&&r>=hf){
            if(c[l]!=c[r]){
                if(a[l]==a[r])ans+=a[l],l++,r--;
                else if(a[l]>a[r])ans+=a[r],a[l]-=a[r],r--;
                else ans+=a[l],a[r]-=a[l],l++;
            }
            else{
                if(a[l]==a[r])l++,r--;
                else if(a[l]>a[r])a[l]-=a[r],r--;
                else a[r]-=a[l],l++;
            }
        }
        cout<<ans;
    }
    return 0;
}
