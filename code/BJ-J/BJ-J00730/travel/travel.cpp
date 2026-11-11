
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char a=c1[0],a1=c1[1],b=c2[0],b1=c2[1];
    if(a==b&&a1==b1) cout << '1';
    else{
        cout << '0' << '0' << '0' << '0';
        return 0;
    }
    a=s1[0],a1=s1[1],b=s2[0],b1=s2[1];
    if(a==b&&a1==b1) cout << '1';
    else{
        cout << '0' << '0' << '0';
        return 0;
    }
    a=s1[2],b=s2[2];
    if('A'<=a&&a<='C'&&b=='D'){
        cout << '0' << '0';
        return 0;
    }else if(a=='D'&&'A'<=b&&b<='C'){
        cout << '0' << '0';
        return 0;
    }else if(a=='F'&&'A'<=b&&b<='C'){
        cout << '0' << '0';
        return 0;
    }else if('A'<=a&&a<='C'&&b=='F'){
        cout << '0' << '0';
        return 0;
    }else cout << '1';
    int a2=(int)a;
    int b2=(int)b;
    if(a2>b2){
        int ans=a2-b2;
        if(ans==1) cout << '1';
        else cout << '0';
    }else{
        int ans=b2-a2;
        if(ans==1) cout << '1';
        else cout << '0';
    }
    return 0;
}
