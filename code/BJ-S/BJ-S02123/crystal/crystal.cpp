#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005];
long long b[500005];
int n;long long m;int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    int i=1,j=1;;
    long long sum=b[1];
    for(j;j<n;){
        if(sum<=m){
            ans=max(ans,j-i+2);
            /*
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
            }
            cout<<endl<<"B:";
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
            }cout<<endl;
            */
            j++;
            sum+=((j-i+1)*b[j]);
            //cout<<"sum:"<<sum<<endl;
        }else{
            //cout<<"flag>>"<<endl;
            sum-=(a[j+1]-a[i]);
            i++;
        }
    }
    cout<<ans;
}
