#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int N=1e9;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m,a[N],cnt=0;
    cin>>n>>m>>cnt;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(cnt<=m){
            if(a[i]==a[i+1]&&a[i-1]==a[i]){
                cnt+=0;
            }else if(a[i]>=m){
                cnt+=0;
            }else{
                a[i]++;
                cnt++;
            }
        }else{
            break;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


