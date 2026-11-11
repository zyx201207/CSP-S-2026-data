#include<iostream>
#define int long long
using namespace std;
const int N=2e5+11;
int n,a[N],before[N],ans=0;
int sum=0,h1=0,lft,h2=0,rht;
char x[N];
int bsearch(int x){
    int l=1,r=n;
    while(l<r){
        int m=(l+r)/2;
        if(x<=before[m]){
            r=m;
        }else{
            l=m+1;
        }
    }
    return l;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>x[i];
        sum+=a[i];
        before[i]=sum;
    }
    if(sum%2==0){
        h1=sum/2,h2=sum/2+1;
    }else{
        h1=sum/2,h2=sum/2+2;
    }
    //cout<<h1<<" "<<h2<<"\n";
    lft=bsearch(h1);
    rht=bsearch(h2);
    while(lft>0&&rht<=n){
    //    cout<<lft<<" "<<rht<<"\n";
        int p=h1-before[lft-1],q=before[rht]+1-h2;
        if(p<q){
            if(x[lft]!=x[rht]){
        //        cout<<x[lft]<<" "<<x[rht]<<"\n";
                ans+=p;
            }
            h1-=p;
            lft--;
            h2+=p;
        }else if(p>q){
            if(x[lft]!=x[rht]){
        //        cout<<x[lft]<<" "<<x[rht]<<"\n";
                ans+=q;
            }
            h1-=q;
            rht++;
            h2+=q;
        }else{
            if(x[lft]!=x[rht]){
         //       cout<<x[lft]<<" "<<x[rht]<<"\n";
                ans+=p;
            }
            h1-=q;
            h2+=q;
            lft--;
            rht++;
        }
    }
    cout<<ans;
    return 0;
}
//OK
