#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
unsigned long long a[200010];
int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n>=2000){
        //cout<<m<<" "<<n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        /*
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        */
        sort(a,a+n);
        /*
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        */
        cout<<a[n-m]<<endl;
        return 0;
    }else{
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(m==1){
            sort(a,a+n);
            cout<<a[n-1]<<endl;
            return 0;
        }
        if(m==n){
            int ans=a[0];
            for(int i=1;i<n;i++){
                ans&=a[i];
            }
            cout<<ans<<endl;
            return 0;
        }
        if(n<=20){
            sort(a,a+n);
        /*
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        */
        cout<<a[n-m]<<endl;
        }
        if(m==2){
            int ans=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j)continue;
                    unsigned long long tem=a[i]&a[j];
                        //cout<<a[i]<<" "<<a[j]<<" "<<tem<<endl;
                    if(tem>ans)ans=tem;
                }
            }
            cout<<ans<<endl;
            return 0;
        }


    }

    return 0;
}
