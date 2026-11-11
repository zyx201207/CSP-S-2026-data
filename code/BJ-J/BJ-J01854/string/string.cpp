#include<bits/stdc++.h>
using namespace std;
int n;
string s1="",s2="";
long long mid;
long long sum;
long long a;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        sum+=a;
        for(int j=1;j<=a;j++){
            s1=s1+c;
        }
    }
    //cout<<s1;
    if(n<=1){
        cout<<0;
        return 0;
    }
    mid=0;
    if(sum%2!=0){
        for(int i=0;i<=(sum-1)/2;i++){
            int k=sum-i-1;
            if(s1[i]!=s1[k]){
                mid++;
            }
        }
    }else{
        for(int i=0;i<(sum/2)+1;i++){
            int k=sum-i;
            if(s1[i]!=s1[k]) mid++;
        }
    }
    cout<<mid;
    return 0;
}
