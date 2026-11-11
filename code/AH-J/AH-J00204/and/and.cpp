#include<bits/stdc++.h>
using namespace std;
bool find(int l[], int n, int m, int ans){
    int ll = 0;
    for(int i = 0;i<n;i++){
        if(l[i]==ans){
            ll++;
        }
    }if(ll+m>n){
    return true;
    }
    return false;
}
int bo(int a[], int n){

}
int main(){
    freopen("and.in","r", stdin);
    freopen("and.out","w",stdout);
    int n, m;
    cin>>n>>m;
    int l[n+10],ls[n+10];
    for(int i = 0;i<n;i++){
        cin>>l[i];

    }
    sort(l,l+n);
    if(m==1){
        cout<<l[n-1];
        return 0;
    }else if(m==n){
        int ans = l[0];
        for(int i = 1;i<n;i++){
            ans = ans&l[i];
        }
        cout<<ans;
        return 0;
    }else if(m==2){
        int ma=-1;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(ma<l[i]&l[j]){
                    ma=l[i]&l[j];
                }
            }
        }
        cout<<ma;
        return 0;
    }else if(find(a[], n, m, 0)||(find(a[], n ,m ,1)&&find(a[], n ,m ,2)))){
    cout<<0;
    }else if(find(a[], n ,m ,1)&&!find(a[], n ,m ,2)){
    cout<<1;
    }else if(find(a[], n ,m ,2)&&!find(a[], n ,m ,1)){
    cout<<2;
    }else if(!(find(a[], n ,m ,0)&&find(a[], n ,m ,1)&&find(a[], n ,m ,2))){
    cout<<3;
    }


    cout<<l[n-2];
    return 0;
}
