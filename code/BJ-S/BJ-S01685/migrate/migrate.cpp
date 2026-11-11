#include<bits/stdc++.h>
using namespace std;

void qwe(int a,int b){
    for(int i=2;i<a;i++){
        if(a%i==0){
            if(b==1){
                cout<<'*'<<i;
            }else{
                cout<<i;
            }
            qwe(a/i,1);
            return;
        }
    }
    cout<<'*'<<a;
}

void q(int a){
    for(int i=0;i<a;i++){
        cout<<' ';
    }
}

int s(int a){
    int num=0;
    while(a>=10){
        a=a/10;
        num++;
    }
    num++;
    return num;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int a,b,out;
    cin>>a>>b;
    cin>>out;
    cout<<"全部："<<endl;
    for(int i=a;i<=b;i++){
        q(s(b)-s(i));
        cout<<i<<' ';
        if(i%out==0){
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<"质数："<<endl;
    bool falg=1;
    for(int i=a;i<=b;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                falg=0;
                break;
            }
        }if(i==1) continue;
        if(falg){
            q(s(b)-s(i));
            cout<<i<<' ';
        }else{
            q(s(b));
            cout<<' ';
        }
        if(i%out==0){
            cout<<endl;
        }
        falg=1;
    }
    cout<<endl;
    cout<<"合数："<<endl;
    falg=1;
    for(int i=a;i<=b;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                falg=0;
                break;
            }
        }
        if(!falg){
            q(s(b)-s(i));
            cout<<i<<' ';
        }else{
            q(s(b));
            cout<<' ';
        }
        if(i%out==0){
            cout<<endl;
        }
        falg=1;
    }
    cout<<endl;
    cout<<"分解质因数"<<endl;
    falg=1;
    for(int i=a;i<=b;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                falg=0;
                break;
            }
        }
        if(!falg){
            cout<<i<<':';
            qwe(i,0);
            cout<<endl;
        }
        falg=1;
    }
    cout<<endl;
    cout<<"完全数："<<endl;

    cout<<endl;
    cout<<"平方数："<<endl;
    for(int i=0;i*i<=b;i++){
        if(i*i>=a){
            cout<<i*i<<' ';
        }
        if(i%out==0){
            cout<<endl;
        }
    }cout<<endl;
    cout<<"立方数："<<endl;
    for(int i=0;i*i*i<=b;i++){
        if(i*i*i>=a){
            cout<<i*i*i<<' ';
        }
        if(i%out==0){
            cout<<endl;
        }
    }
    return 0;
}
