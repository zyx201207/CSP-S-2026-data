#include<bits/stdc++.h>
using namespace std;
long long b[2000090];
long long k=0;
char c[2000000];
long long a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>a;
    for(long long i=1;i<=a;i++){
        cin>>b[i]>>c[i];
        for(long long j=1;j<=b[i];j++){k++;
            s[k]=c[i];
        }
    }
    string s1;
    long long cnt=k;
    for(long long i=1;i<=k;i++){
        s1[i]=s[cnt];
        cnt--;
    }
    bool kl=false;
    long long mj=0;
    for(long long i=1;i<=k;i++){
        if(s1[i]!=s[i]){
            kl=true;
            mj++;
        }
    }
    if(kl==false)cout<<0;
    else cout<<mj/2;
	return 0;
}
