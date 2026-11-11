#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,p,an=0;
    string s,r;
    char e;
    //s+=' ';
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>e;
        for(int j=0;j<a;j++){
            s+=e;
        }
    }
    //cout<<s<<" ";
    int q=s.size();
    if(q%2==0) p=q/2;
    else p=q/2+1;
    //cout<<p;
    for(int i=p;i<=q-1;i++){
            //cout<<"1"<<s[i]<<" ";
            //cout<<2<<s[q-i-1]<<" ";
            if(s[i]!=s[q-i-1]) an++;
    }
    //reverse(s.begin(),s.end());
    //cout<<s;
    cout<<an;
    return 0;
}
