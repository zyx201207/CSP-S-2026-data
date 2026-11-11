#include <bits/stdc++.h>
using namespace std;
string sum ;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,n[100000001],ch=0;
    char m[1000000001];
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>n[i];
        cin>>m[i];
        sum+=n[i]*m[i];
        
    }
    if(sum.size%2==1){
        for(intj=1;j<=(sum.size-1)/2;j++){
            if(sum[j]!=sum[sum.size-j+1]){
                ch++;
            }
            
        }
        
    }else{
        for(intj=1;j<=sum.size/2;j++){
            if(sum[j]!=sum[sum.size-j+1]){
                ch++;
            }
            
    }
    cout<<ch;
    
    return 0;
}

