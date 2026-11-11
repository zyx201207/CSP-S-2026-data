#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int l,r,x;
    long long sum=0,ans=0;
    string s1,s2,s3;
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int n;
        string s;
        cin>>n>>s;
        sum+=n;
        while(n){
            s1+=s;
            n-=1;
        }
        s3=s1;
        for(int i=s1.size();i>0;i--){
            s2+=s1[i];
        }
    }
        if(s3==s2){
            cout<<'0'<<endl;
            return 0;
        }else{
            l=s1[0],r=s1[s1.size()-1],x=s1.size()/2+1;
            while(x!=0){
                //l+=1;
                //r-=1;
                if(l!=r){
                    ans++;
                    x-=1;
                    l+=1;
                    r-=1;
                    //cout<<l<<" "<<r<<" "<<x;
                }else{
                    x-=1;
                    l+=1;
                    r-=1;
                    //cout<<l<<" "<<r<<" "<<x;
                }
            }
        }
    cout<<ans;
}
