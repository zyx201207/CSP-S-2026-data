#include<bits/stdc++.h>
using namespace std;
int n;
string ans;
int d;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    int w=0;
    for(int i=0;i<n;i++){
        int num;
        char c;
        cin>>num>>c;
        for(int j=w;j<w+num;j++){
            ans[j]=c;
        }
        w+=num;
    }
    for(int i=0;i<w/2;i++){
       if(ans[i]!=ans[w-1]){
            d+=1;
       }
    }
    cout<<d;
    return 0;
}
