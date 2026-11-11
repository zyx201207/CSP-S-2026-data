#include<bits/stdc++.h>
using namespace std;
long long num,n;
string s,a;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>n;
        cin>>a;
        for(int j=0;j<n;j++){
            s+=a;
        }
    }
    long long len1=s.size();
    long long mid=(len1+1)/2;
    string a1,b1;
    for(int i=0;i<mid;i++){
        a1+=s[i];
    }
    for(int i=len1-1;i>=mid-1;i--){
        b1+=s[i];
    }
    long long sum=0;
    for(int i=0;i<mid;i++){
        //cout<<a1[i]<<" "<<b1[i]<<endl;
        if(a1[i]!=b1[i]) sum++;
    }
    cout<<sum;
}

