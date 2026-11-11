#include<bits/stdc++.h>
using namespace std;
int si(string n){
    return (n[0]-'0')*10+n[1]-'0';
}
bool xl(char a,char b){
    int ma=max(int(a),int(b));
    int mi=min(int(a),int(b));
    if(ma==int('F')&&mi==int('D'))return 1;
    if(ma==int('C')&&mi==int('B'))return 1;
    if(ma==int('C')&&mi==int('A'))return 1;
    if(ma==int('B')&&mi==int('A'))return 1;
    return 0;
}
bool xl2(char a,char b){
    int ma=max(int(a),int(b));
    int mi=min(int(a),int(b));
    if(ma==mi+1)return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(si(a)==si(c)){
        cout<<1;
        if(si(b)==si(d)){
            cout<<1;
            if(xl(b[2],d[2])){
                    cout<<1;
                    if(xl2(b[2],d[2])){
                        cout<<1;
                        return 0;
                    }else{
                        cout<<0;
                        return 0;
                    }
            }
            else{
                cout<<0<<0;
                return 0;
            }
        }else{
            cout<<0<<0<<0;
            return 0;
        }
    }else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    return 0;
}
