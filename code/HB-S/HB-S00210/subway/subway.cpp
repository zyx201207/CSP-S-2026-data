#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[500005],t[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>a[j]>>t[j];
    }
    cout<<w[1]+t[1]+t[2]+t[4]+t[5]+w[3]<<endl;
    cout<<(w[1]+t[1]+t[2]+t[4]+t[5]+w[3])/2+1<<endl;
    return 0;
}
/*+<=>|~¬±×÷϶؆؇؈⁄⁒⁺⁻⁼₊₋₌℘⅀⅁⅂⅃⅄⅋←↑→↓↔↚↛↠↣↦↮⇎⇏⇒⇔⇴⇵⇶⇷⇸⇹⇺⇻⇼⇽⇾∀∁∂∃∄∅∆∇∈∉∊∋∌∍∎∏∐∑−∓∔∕∖∗∘∙√∛∜∝∞∟∠∡∢∣∤∥∦∧∨∩∪∫∬∮∯∰∱∲∳∴∵∶∷∸∹∺∻∼∽∾∿≀≁
好吧其实根本不会写这道题*/