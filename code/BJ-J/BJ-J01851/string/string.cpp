#include <bits/stdc++.h>

using namespace std;
int n;
long long l,sum;
long long p[1000005];
char s[1000005];
long long gcd(int x,int y){
    if(y==0){
        return x;
    }
    return gcd(y,x%y);
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    cin>>p[1]>>s[1];
    long long gc=p[1];
    for(int i=2;i<=n;i++){
        cin>>p[i]>>s[i];
        if(gc!=1)
            gc=gcd(gc,p[i]);
    }
    string str;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=p[i]/gc;j++){
            str+=s[i];
        }
        l+=p[i]/gc;
    }//cout<<str<<" "<<l<<" "<<gc<<"\n";
    for(int i=0;i<l/2;i++){
        //cout<<str[i]<<" "<<str[l-i-1]<<"\n";
        if(str[i]!=str[l-i-1])sum++;
    }
    cout<<sum*gc;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
