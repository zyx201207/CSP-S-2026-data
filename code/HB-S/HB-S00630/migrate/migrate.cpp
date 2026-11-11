#include<bits/stdc++.h>
using namespace std;

#define var long long
#define ln '\n'
#define Pt(x) fixed<<setpericison(x)
#define strsiz(x) (var)(x.size())

namespace solve1{
    const var MaxN=310;
    var n,d;
    var p[MaxN];
    var dif[MaxN];
    bitset<MaxN> f[MaxN][MaxN];

    void cut(string &p){
        while(strsiz(p) && p.back()=='0') p.pop_back();
        var t=0;
        while(strsiz(p) && p[t]=='0') t++;
        p=p.substr(t);
        return;
    }

    void solve(){
        memset(f,0,sizeof(f));

        cin>>n>>d;
        for(var i=1;i<=n;i++){
            cin>>p[i];
        }

        for(var i=1;i<=n-1;i++){
            dif[i]=p[i+1]-p[i];
        }

        for(var a=1;a<=n;a++){
            var res=0,sum=0;
            bitset<MaxN> u=0;
            u[a]=1;
            for(var b=a;b<=n-1;b++){
                if(sum+dif[b]<=d){
                    sum+=dif[b];
                }else{
                    sum=dif[b];
                    u[b]=1;
                    res++;
                }

                u[b+1]=1;
                f[a][b+1]=u;
                u[b+1]=0;
            }
        }

        var ans=0;

        reverse(dif+1,dif+n);

        for(var a=1;a<=n;a++){
            var res=0,sum=0;
            bitset<MaxN> u=0;
            u[a]=1;
            for(var b=a;b<=n-1;b++){
                if(sum+dif[b]<=d){
                    sum+=dif[b];
                }else{
                    sum=dif[b];
                    u[b]=1;
                    res++;
                }

                u[b+1]=1;
                string l=u.to_string();
                string r=f[a][b+1].to_string();
                cut(l),cut(r);
                bool f=(l==r);
                reverse(l.begin(),l.end());
                ans+=(l!=r && f);
                u[b+1]=0;
            }
        }

        cout<<ans<<ln;
        return;
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    var c,t;
    cin>>c>>t;
    while(t--){
        if(c>=1 && c<=10){
            solve1::solve();
        }else{
            cout<<"0"<<ln;
        }
        
    }

    return 0;
}
/*
g++ migrate.cpp -o migrate.exe -O2 -std=c++14
./migrate.exe < migrate2.in > migrate.out
diff migrate2.ans migrate.out

1 - 4 : 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011010
2 - 5 : 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000110100
1 + 4 : 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011010
2 + 5 : 0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100100
*/