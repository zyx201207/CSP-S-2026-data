#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int a,n=1;
    string e="";
    long long b=0,sum=0,d=0;
    cin>>a;
    vector <char> st(a+1);
    vector <long long> hd(a+1);
    for(int i=1;i<=a;i++){
        cin>>hd[i]>>st[i];
        b+=hd[i];
        if(a%2==0 and n!=0){
            n=2;
            if(i==a/2){
                e=e+st[i];
                n-=1;
            }
        }else{
            if(i==a/2 and n==1){
                n-=1;
                e+=st[i];
            }
        }
    }
    //yes
    if(a==1){
        cout<<0;
        return 0;
    }
    if(a%2==0){
        b/=2;
        sum+=b;
        //cout<<b<<" "<<sum<<endl;
    }else{
        b/=2;
        sum+=b;
        //cout<<b<<" "<<sum<<endl;
    }
    //ok
    if(a<=2 and hd[1]!=hd[2]){
        cout<<min(hd[1],hd[2]);
        return 0;
    }if(a<=2 and hd[1]==hd[2]){
        cout<<0;
        return 0;
    }
    //ok
    int o=1;
    //ok
    for(int i=1;i<=a;i++){
        if(st[i]==st[a-i+1] and i!=a-i+1){
            sum-=hd[a-i+1];
        }
        if(st[i]==st[i+1]){
            continue;
        }else{
            o=0;
        }
    }
    if(o){
        cout<<0;
        return 0;
    }
    cout<<sum;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
