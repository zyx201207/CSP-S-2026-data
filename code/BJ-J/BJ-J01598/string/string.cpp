#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
#define pb emplace_back

ll a[200005],st[200005];

char c[200005];

ll s;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll k=0;
    while(n--){
        cin>>a[++k]>>c[k];
        if(c[k]==c[k-1]){
            a[k-1]+=a[k];
            k--;
        }
        if(k==1) st[k]=1;
        else st[k]=st[k-1]+a[k-1];
    }
    st[k+1]=st[k]+a[k];/*
    for(int i=1;i<=k+1;i++){
        cout<<a[i]<<' '<<c[i]<<' '<<st[i]<<endl;
    }
    cout<<endl<<endl<<endl;*/
    ll p1=1,p2=k,s1=1,s2=st[k+1]-1;
    for(;;){
        //cout<<p1<<' '<<s1<<' '<<p2<<' '<<s2/*<<"   "<<q1<<' '<<q2*/<<endl;
        if(p1==p2||s1>=s2){
            break;
        }
        ll q1=st[p1]+a[p1]-s1;
        ll q2=s2-st[p2]+1;
        if(c[p1]!=c[p2]){
            s+=min(q1,q2);
        }
        if(q1<q2){
            p1++;
            s1=st[p1];
            s2-=q1;
        }else if(q1>q2){
            p2--;
            s2=st[p2+1]-1;
            s1+=q2;
        }else{
            p1++;
            p2--;
            s1=st[p1];
            s2=st[p2+1]-1;
        }
    }
    cout<<s;
    return 0;
}
