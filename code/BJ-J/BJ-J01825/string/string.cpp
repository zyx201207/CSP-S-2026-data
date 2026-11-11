#include<bits/stdc++.h>

using namespace std;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long s=a[1];
    char cc=c[1];
    int ss=0;//0=l,1=r
    int l=1,r=n+1;
        while(l!=r){
        if(ss==0){
            r--;
            if(c[r]!=cc){
                sum=sum+min(s,a[r]);
                if(s>a[r])s-=a[r];
                else {
                    ss=1;
                    s=a[r]-s;
                    cc=c[r];
                }
            }else{
                if(s>a[r])s-=a[r];
                else {
                    ss=1;
                    s=a[r]-s;
                }
            }
        }
        else {
            l++;
            if(c[l]!=cc){
                sum+=min(a[l],s);
                if(s>a[l])s-=a[l];
                else {
                    ss=0;
                    s=a[l]-s;
                    cc=c[l];
                }
            }else{
                if(s>a[l])s-=a[l];
                else{
                    ss=0;
                    s=a[l]-s;
                }
            }
        }
    }
    //cout<<s<<" "<<a[r]<<endl;
    cout<<sum;
    return 0;
}