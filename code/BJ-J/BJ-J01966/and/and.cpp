#include <bits/stdc++.h>
using namespace std ;
string s[200010] ;
int main(){
    freopen("and.in","r",stdin) ;
    freopen("and.out","w",stdout) ;
    long long n,m,x ;
    cin >> n >> m ;
    if (m==1){
        long long x,maxx=-1 ;
        for (int i=1 ; i<=n ; i++){
            cin >> x ;
            maxx=max(maxx,x) ;
        }
        cout << maxx ;
        return 0 ;
    }
    for (int i=1 ; i<=n ; i++){
        cin >> x ;
        int j=1 ;
        while (x){
            s[i]+=(char((x%2)+'0')) ;
            x/=2 ;
            j++ ;
        }
    }
    if (m==2){
        long long maxx=-1 ;
        for (int i=1 ; i<=n ; i++){
            for (int j=i+1 ; j<=n ; j++){
                string st=" " ;
                for (int k=1 ; k<=max(s[i].size(),s[j].size()) ; k++){
                    if (s[i].size()<k || s[j].size()<k){
                        st+='0' ;
                    }
                    else {
                        if (s[i][k]=='1' && s[j][k]=='1'){
                            st+='1' ;
                        }
                        else {
                            st+='0' ;
                        }
                    }
                }
                long long ans=0,l=1 ;
                for (int k=st.size()-1 ; k>=1 ; k--){
                    if (st[k]=='1'){
                        ans+=l ;
                    }
                    l*=2 ;
                }
                maxx=max(maxx,ans) ;
            }
        }
        cout << maxx ;
    }
    return 0 ;
}
