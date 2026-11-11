#include<bits/stdc++.h>
using namespace std;
int main(){//abbcccddddcccba
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string a/*[200002]*/;
    int n,len;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        string c;
        cin>>x>>c;
        len+=x;
        for(int j=0;j<x;j++){
            a.append(c);
        }
    }
    string ra=a;
    reverse(ra.begin(),ra.end());
    if(ra==a){
        cout<<0;
        return 0;
    }
    int l=0,r=len-1,cnt=0;
    while(l<=r){

        if(a[l]==a[r]){
            //cout<<"pass:"<<a[l]<<","<<a[r]<<endl;
            l++;r--;
            continue;
        }
        //cout<<l<<" "<<r<<" "<<a[l]<<","<<a[r]<<endl;
        a[r]=a[l];
        cnt++;
        l++;r--;
    }
    cout<<cnt;
    return 0;
}
