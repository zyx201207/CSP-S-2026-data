#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    long long a,b,c,d,gs,gk;
    char s,k;
    string n,m;
    cin >> a >> c >> s >> b >> d >> k;
    for(int i=0;i<5;i++){
        if(i==4){
            i++;
        }
        if(i<=2){
            n[i] = 'A'+i;
        } else{
            m[i] = 'A'+i;
        }
        if(s==char(n[i])||s==char(m[i])){
            gs=i+1;
        }
        if(k==char(n[i])||k==char(m[i])){
            gk=i+1;
        }
    }
    if(a==1||a==16||b==1||b==16){
        return 0;
    }
    if(a==b){
        cout << "1";
        if(c==d){
            cout << "1";
            if(gk>gs){
                if(gk-gs<=2){
                    if(s=='C'){
                        if(k=='D'){
                            cout << "00";
                            return 0;
                        } else{
                            cout << "1";
                            if(gk-gs==1){
                                cout << "1";
                                return 0;
                            } else{
                                cout << "0";
                                return 0;
                            }
                        }
                    } else if(s=='D'){
                        if(k=='C'&&k=='B'){
                            cout << "00";
                            return 0;
                        } else{
                            cout << "1";
                            if(gk-gs==1){
                                cout << "1";
                                return 0;
                            } else{
                                cout << "0";
                                return 0;
                            }
                        }
                    }
                }
            } else{
                if(gs-gk<=2){
                    if(s=='C'){
                        if(k=='D'){
                            cout << "00";
                            return 0;
                        } else{
                            cout << "1";
                            if(gs-gk==1){
                                cout << "1";
                                return 0;
                            } else{
                                cout << "0";
                                return 0;
                            }
                        }
                    } else if(s=='D'){
                        if(k=='C'&&k=='B'){
                            cout << "00";
                            return 0;
                        } else{
                            cout << "1";
                            if(gs-gk==1){
                                cout << "1";
                                return 0;
                            } else{
                                cout << "0";
                                return 0;
                            }
                        }
                    }
                }
            }
        } else{
            cout << "000";
            return 0;
        }
    } else{
        cout << "0000";
        return 0;
    }
}
