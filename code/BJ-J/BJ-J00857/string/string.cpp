#include<bits/stdc++.h>
using namespace std;
struct node{
    int n;
    char c;
}a[200005];
node a1[200009];
unsigned long long b[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    bool issame=1; //is same
    unsigned long long tn=0;//true n
    for(int i=1;i<=n;i++){
        int u;char c;
        cin>>u>>c;
        tn+=(unsigned long long)u;
        b[i]=tn;
        a[i].n=u;
        a[i].c=c;
        a1[i].c=c;
        a1[i].n=u;
        if(c!=a[1].c)issame=0;
        //cout<<b[i]<<" ";
    }
   // cout<<"\n";
    if(n==1||issame){
        cout<<0;
        return 0;
    }
    if(n==2){
        if(a[1].c==a[2].c){
            cout<<0;return 0;
        }
    }
    if(tn<=10000000){
        string ss="";
        for(int i=1;i<=n;i++){
            while(a[i].n--)ss+=a[i].c;
        }
        //cout<<ss<<endl;
        int cnt=0;
        ss=' '+ss;
        for(int i=1;i<=tn/2;i++){
            if(ss[i]!=ss[tn-i+1])cnt++;
        }
        cout<<cnt;
        return 0;
    }
    int q=upper_bound(b+1,b+n+1,tn/2)-b;
    if(tn%2==0){
        if(a1[q].n!=1){
            n++;
            a1[q].n=b[q]-tn/2;
            a1[q+1].n=a[q].n-a1[q].n;
            a1[q+1].c=a[q].c;
            for(int i=q+2;i<=n+1;i++){
                a1[i].c=a[i-1].c;
                a1[i].n=a[i-1].n;
            }
        }
    }
    else{
        if(a1[q].n==1){
            //cout<<111<<endl;
            tn--;
            n--;
            for(int i=q;i<n;i++){
                b[i]--;
                a1[i].c=a[i+1].c;
                a1[i].n=a[i+1].n;
            }
        }
        else if(a1[q].n==2){
            //cout<<222<<endl;
            tn--;
            a1[q].n--;
            for(int i=q;i<=n;i++){
                b[q]--;
            }
        }
        else{
       //     cout<<333<<" ";
            tn--;
            a1[q].n--;
            b[q]--;
            a1[q].n=b[q]-tn/2;
            a1[q+1].n=a[q].n-a1[q].n;
            a1[q+1].c=a[q].c;
         //   cout<<a1[q].n<<" "<<a1[q+1].n<<" "<<a[q].n<<endl;
            for(int i=q+2;i<=n+1;i++){
                b[i]--;
                a1[i].c=a[i-1].c;
                a1[i].n=a[i-1].n;
            }
        }
    }
    char zhe;
    int lef=0;
    int j=n;
    unsigned long long cnt1=0,cnt2=0;
    for(int i=1;i<q;i++){
        cnt2+=a1[i].n;
        if(lef==0){
            zhe=a1[j].c;
            lef=a1[j].n;
        }
        int k=a1[i].n;
        while(k>=0){
         //   cout<<i<<" "<<j<<endl;
            k-=lef;
            if(zhe!=a1[i].c){
                if(k>=0){
                    cnt1+=lef;
                }
                else{
                    cnt1+=lef+k;
                }
            }
            if(k>=0){
                j--;
                zhe=a1[j].c;
                lef=a1[j].n;
            }
            else{
                lef=-k;
            }
        }
    }
   // cout<<q<<" "<<lef<<" "<<cnt2<<" "<<tn-cnt2<<" ";
    cout<<cnt1;
    return 0;
}
