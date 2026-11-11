#include<bits/stdc++.h>
using namespace std;
#define int long long
struct sy{
    size_t cd;
    string zf;
}cy[2000010];
int a[2000010];
string v[2000010];
int ans;
int t[40];
bool cmp(sy a,sy b){
    if(a.cd!=b.cd){
        return a.cd>b.cd;
    }else{
        return a.zf>b.zf;
    }
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        string s;
        s="";
        int a_=a[i];
        char ch;
        int jo;
        int cnt=1;
        while(a_!=0){
            ch='0';
            jo=a_&1;
            if(jo==1){
                t[cnt]++;
            }
            ch+=jo;
            s+=ch;
            cnt++;
            a_>>=1;
        }
        string s_=s;
        for(int i=0;i<s_.size();i++){
            s[i]=s_[s_.size()-1-i];
        }
        cy[i].zf=s;
        cy[i].cd=s.size();
    }
    sort(cy+1,cy+n+1,cmp);
    int cnt=1;
    for(int i=30;i>=1;i--){
        if(t[i]>=m){
            for(int j=1;j<=n;j++){
                if(cy[j].zf[cy[j].zf.size()-i]=='1'){
                    v[cnt]=cy[j].zf;
                    if(cnt==m){
                        break;
                    }
                    cnt++;
                    for(int k=0;k<cy[j].zf.size();k++){
                        if(cy[j].zf[k]=='1'){
                            t[k+1]--;
                        }
                    }
                }
            }
        }
        if(cnt==m){
            break;
        }
    }
    string s=v[1];
    for(int i=2;i<=m;i++){
        for(int j=0;j<s.size();j++){
            if(s[j]=='1'&&v[i][j]=='1'){
                s[j]='1';
            }else{
                s[j]='0';
            }
        }
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            ans+=pow(2,(s.size()-1-i));
        }
    }
    cout<<ans<<endl;
    return 0;
}
