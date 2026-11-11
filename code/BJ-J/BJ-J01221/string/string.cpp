#include<bits/stdc++.h>
using namespace std;
long long n,a,p;
char r;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>r;
        for(long long j=0;j<a;j++){
                s+=r;
        }
    }
    long long i=0;
    long long j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            p++;
        }
        i++;
        j--;
    }
    cout<<p;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
