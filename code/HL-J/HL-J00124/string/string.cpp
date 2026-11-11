#include <bits/stdc++.h>
using namespace std;
long long x[100010];
long long sum=0;
char s[100010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;

    string s=" ",s_1=" ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>s[i];
        s+=s[i];
        s_1+=s[i]*x[i];
    }
    bool b1=1,b2=1;
    for(int i=2;i<=n;i++){
        if(x[i]!=x[i-1]){
            b1=0;
        }
        if(s[i]!=s[i-1]){
            b2=0;
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    else if(n==2){
        if(s[1]==s[2]){
            cout<<0;
            return 0;
        }
        else{
            cout<<1;
            //cout<<endl<<s[0]<<" "<<s[1];
            return 0;
        }
    }
    else if(b2==1){
        cout<<0;
        return 0;
    }
    else if(b1==1){
        int j=1,k=n;
        while(j<=k){
        if(s[j]==s[k]){
            j++;
            k--;
        }
        else{
            sum+=x[j];
            j++;
            k--;
        }
        }
        cout<<sum;
        return 0;
    }
    /*else if(n<=10){
        long long j=1;k=s_1.size();
        while(j<=k){
        if(s[j]==s[k]){
            j++;
            k--;
        }
        else{
            sum++;
            j++;
            k--;
        }
        }
        cout<<sum;
        return 0;
    }
    else{
        cout<<s_1.size()/2;
    }*/
    }
    return 0;
}

