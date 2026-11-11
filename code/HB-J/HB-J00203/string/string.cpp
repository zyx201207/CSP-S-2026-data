#include<bits/stdc++.h>
using namespace std;
long long n,a,sum;
char c;
string s,s1;
void f(string s){
    for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
        swap(s[i],s[j]);
    }
    return ;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a;
        cin>>c;
        for(long long j=0;j<a;j++){
            s+=c;
        }
    }
    s1=s;
    f(s1);
    cout<<endl<<s<<endl<<s1;
    if(s1==s){
        cout<<0;
    }
    else{
        int i=0;
        while(s1!=s){
            s1[i]=s[i];
            f(s);
            s[i]=s1[i];
            f(s);
            sum++;
            i++;
        }
        cout<<endl<<s<<endl<<s1;
    }
    return 0;
}
