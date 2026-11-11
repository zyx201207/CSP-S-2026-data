#include<bits/stdc++.h>
using namespace std;
struct st{
    long long h;
    char c;
}ar[200026];
long long n,len;
unsigned long long ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i].h>>ar[i].c;
    }
    long long t=ar[0].h;
    bool b=true;
    for(int i=0;i<n;i++){
        if(ar[i].h!=t) b=false;
        else t=ar[i].h;
    }
    if(b==true){
        for(int i=0;i<n;i++){
            s+=ar[i].c;
        }
        len=s.size();
        int j=len-1;
        for(int i=0;i<len;i++){
		    if(j<i) break;
            if(s[i]!=s[j]) ans+=ar[i].h;
            j--;
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(ar[i].h!=t) b=false;
            else t=ar[i].h;
            for(int j=0;j<ar[i].h;j++){
                s+=ar[i].c;
            }
        }
        len=s.size();
        int j=len-1;
        for(int i=0;i<len;i++){
    		if(j<i) break;
            if(s[i]!=s[j]) ans++;
            j--;
        }
    }
    cout<<ans;
    return 0;
}
//while(1) rp++;
//I AK IOI!!!
