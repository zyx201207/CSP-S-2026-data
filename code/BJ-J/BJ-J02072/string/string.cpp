#include<bits/stdc++.h>
using namespace std;
long long n;
int a[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int l=1,r=n;
    long long cnt=0;
    while(l<=r){
        if(a[l].second==a[r].second){
            if(a[l].first>a[r].first){
                a[l].first==a[r].first;
                r--;
            }else if(a[i].first==a[r].first){
                l++;
                r--;
            }else{
                a[r].first-=a[l].first;
                r--;
            }
        }
        cnt+=min(a[r].first,a[l].first);
        if(a[l].first>a[r].first){
            a[l].first-=a[r].first;
        }
    }
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
