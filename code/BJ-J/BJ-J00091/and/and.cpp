#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#define clientaa
int num[200000];
using namespace std;

int main(){
    #ifndef clientaaa
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    #endif
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n-1;j++){
            if(num[j]<num[j+1]){
                swap(num[j],num[j+1]);
            }
        }
    }
    int ans=num[0];
    for(int i=0;i<m;i++){
        ans=ans&num[i];
    }
    cout<<ans;
    return 0;
}
