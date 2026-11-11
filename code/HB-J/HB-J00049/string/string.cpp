#include <bits/stdc++.h>
using namespace std;
const int MAXL=300000;
long long number_[MAXL];
string word_[MAXL];
string l[MAXL];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string ljx;
    cin>>n;
    for(int i=0;i<=n-1;i++){
        cin>>number_[i];
        cin>>word_[i];
    }

    for(int i=0;i<=n-1;i++){
        for(long long j=0;j<=number_[i]-1;j++){
            l[i]=l[i]+word_[i];
        }
        ljx=ljx+l[i];
    }
    long long  cnt=0;
    for(long long i=0;i<=floor(ljx.size()/2)-1;i++){
        if(ljx[i]==ljx[floor(ljx.size())-1-i]) cnt++;
    }
    cout<< floor(ljx.size()/2)-cnt;
    return 0;
}

