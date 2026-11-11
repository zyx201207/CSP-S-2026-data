#include <bits/stdc++.h>
using namespace std;

string s,s1,s2;
int n,sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        char c;
        cin>>num>>c;
        for(int j=0;j<num;j++){
            s+=c;
        }
    }
    int L=s.size();
    int l=L/2;
    if(L%2==1){
        s[L/2]=s[L/2+1];
        for(int i=ceil(L/2);i<L;i++)
        s[i]=s[i+1];
    }
    for(int i=0;i<l;i++){
        s1+=s[i];
    }
    for(int i=l;i<L-1;i++){
        s2+=s[i];
    }
    if(s2+s2!=s){
        for(int i=0;i<l;i++){
            if(s1[i]!=s2[L+1-i])
                sum++;
        }}
    cout<<sum;
    return 0;}
