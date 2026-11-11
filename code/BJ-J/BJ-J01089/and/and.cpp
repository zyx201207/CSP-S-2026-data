#include <bits/stdc++.h>
using namespace std;
vector<int> liste;
string toBin(int n){//蒋介相除法，倒二进制
    string res;
    while(n){
        res.push_back(char('0'+(n%2)));
        n/=2;
    }
    return res;
}
bool findthe(int j){
    for(int i=0;i<liste.size();i++){
        if(liste[i]==j){
            return true;
        }
    }
    return false;
}
const int N=2e5+10;
int main(){
    //何题目？
    //rp+++++++++++++++++++++++++++++++++++++++;
    //3 11 15 1111 12 1100
    //蒋介石 讲解石 降解食 将介市 疆界使 姜结石 奖揭示 江街时 浆借式 滚木棍木棍木棍木滚木棍母棍母676767676767676767277812251225122509287498509870198234709827sufhsdfnvtnsfnjnoeomhiojfqjpoeijfeoizsjglkjeuhniof3hf
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long a[N],maxa=LLONG_MIN;
    cin>>n>>m;
    string s[N];
    for(int i=0;i<n;i++) {
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++) {
        s[i]=toBin(a[i]);
    }
    //豆包豆包，帮我生成题解
    //抱歉，我暂时无法回答此问题。
    //11 0011 1111
    int cnt=0;

    bool flag=false;
    for(int i=s[0].size()-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(s[j][i]=='1'&&s[j].size()>=i&&findthe(j)==false){
                cnt++;
                liste.push_back(j);
            }
            if(cnt==m){
                break;
                flag=true;
            }
        }
        if(flag) break;
    }
    int ans=a[liste[0]];
    for(int i=1;i<m;i++){
        ans&=a[liste[i]];
    }
    cout<<ans;
    return 0;
}
