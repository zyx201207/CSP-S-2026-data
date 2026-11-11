#include <bits/stdc++.h>
#define LL long long
#define gc getchar_unlocked

using namespace std;

int cnt=0;
string c1,s1,c2,s2;

inline int num(string s){
    int res=0;
    for(int i=0;i<s.size()&&isdigit(s[i]);i++){
        res*=10;
        res+=s[i]-'0';
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout<<1; cnt++;
        if(num(s1)==num(s2)){
            cout<<1; cnt++;
            if( ((s1[s1.size()-1])<='C' && (s2[s2.size()-1])<='C') || ((s1[s1.size()-1])>='D' && (s2[s2.size()-1])>='D') ){
                cout<<1; cnt++;
                if(abs(s1[s1.size()-1]-s2[s2.size()-1])==1){
                    cout<<1; cnt++;
                }
            }
        }
    }
    while(cnt<4){cout<<0; cnt++;}
    cout << endl;

    return 0;
}
