#include<bits/stdc++.h>
using namespace std;
int out(string s){
    int c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9') c=c*10+(s[i]-'0');
    }
    return c;
}
int hout(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='E') return int(s[i]);
    }
}
int main(){
    freopen("travel1.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string t1,t2;
    cin >> c1 >> t1 >> c2 >> t2;

    if(c1==c2){
        cout << "1";
        int p1=out(t1),p2=out(t2);
        if(p1==p2){
            cout << "1";
            int ch1=hout(t1),ch2=hout(t2);//65-69
            //cout << ch1 << "   " << ch2 << endl;
            if(ch1==65||ch1==66||ch1==67){

                if(ch2==65||ch2==66||ch2==67){
                    cout << "1";
                    if((max(ch1,ch2)-min(ch1,ch2))==1) cout << "1";
                    else cout << "0";
                }
                else cout << "00";
            }
            else if(ch1==68||ch1==69){
                if(ch2==68||ch2==69){
                    cout << "11";
                }
                else cout << "00";
            }
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
