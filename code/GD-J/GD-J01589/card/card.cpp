#include<bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;

#define mkp make_pair
#define PII pair<int,int>
#define pb push_back

using namespace std;

void qread(int &sum){
    sum=0;
    char ch=getchar();
    while(ch<'0' || ch>'9'){ch=getchar();}
    while(ch>='0' && ch<='9'){sum=(sum<<1)+(sum<<3)+ch-48;ch=getchar();}
    return;
}

void qprint(int x){
	if(x>9) qprint(x/10);
	putchar(x%10+48);
	return;
}

const int N=5e5+10,M=3e5+10;

int n,m;
int a[N];

vector<int>g[M];
// int len[M];
int ans[M];

int main(){
	freopen("card.in","r",stdin);
//	freopen("card6.in","r",stdin);
	freopen("card.out","w",stdout);
	
    // scanf("%d %d",&n,&m);
    qread(n),qread(m);
    // for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) qread(a[i]);
    for(int i=n;i;i--) g[a[i]].pb(i);
    // for(int i=1;i<=m;i++) len[i]=g[i].size();

    for(int i=1;i<=n;i++){
        int t=i,val=a[t];
        // while(t<=n){
        //     if(g[val][len[val]]==t){
        //         ans[val]++;
        //         t++;
        //     }
        //     else{
        //         t=g[val][len[val]]
        //     }
        // }
        // if(g[val][0]<t){

        // }
        // else
        while(t<=n){
            // if(g[val][0]>t){
            //     t=g[val][0]+1;
            //     // ans[val]++;
            // }
            // else{// equal

            // }
            val=a[t];
            t=g[val][0]+1;
            ans[val]++;
        }
    }

    // for(int i=1;i<=m;i++) printf("%d ",ans[i]);putchar('\n');
//    printf("%d",ans[1]);
//    for(int i=2;i<=m;i++) printf(" %d",ans[i]);putchar('\n');
    qprint(ans[1]);
    for(int i=2;i<=m;i++) printf(" "),qprint(ans[i]);putchar('\n');
	return 0;
}

/*
// card0.cpp
#include<bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;

#define mkp make_pair
#define PII pair<int,int>
#define pb push_back

using namespace std;

void qread(int &sum){
    sum=0;
    char ch=getchar();
    while(ch<'0' || ch>'9'){ch=getchar();}
    while(ch>='0' && ch<='9'){sum=(sum<<1)+(sum<<3)+ch-48;ch=getchar();}
    return;
}

const int N=5e5+10,M=3e5+10;

int n,m;
int a[N];

vector<int>g[M];
// int len[M];
int ans[M];
bool bz[M];

// set<int> s;

struct biao{
    // int pre,suf;
    // int suf;
    int val;
}d[M];
int pp;
int cnt[M];

int main(){
//	freopen("card.in","r",stdin);
	freopen("card3.in","r",stdin);
	freopen("card.out","w",stdout);
	
    // scanf("%d %d",&n,&m);
    qread(n),qread(m);
    // for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) qread(a[i]);
    // for(int i=n;i;i--) g[a[i]].pb(i);
    // for(int i=1;i<=m;i++) len[i]=g[i].size();

    // pp=m+1;
    // for(int i=n;i>=1;i--){
    //     if(bz[a[i]]){
    //         for(;d[pp].val!=a[i] && pp<=m;pp++){

    //         }
    //         pp++;
    //         cout<<"ppp : "<<pp<<"\n";
    //     }
    //     // else{
    //     //     bz[a[i]]=1;
    //     //     // ... ans[]=1;
    //     // }
    //     bz[a[i]]=1;
    //     pp--;
    //     d[pp].val=a[i];

    //     cout<<"pp= "<<pp<<", m= "<<m<<"\n";
    //     for(int j=pp;j<=m;j++) ans[d[j].val]++,cout<<d[j].val<<" ";cout<<"\n";
    // }

    for(int i=0;i<=m;i++) d[i].val=0;

    pp=0;
    for(int i=n;i>=1;i--){
        if(bz[a[i]]){
            // for(;d[pp].val!=a[i] && pp>=1;pp--){

            // }
            while(d[pp].val!=a[i] && pp>=1){
                // if(cnt[d[pp].val]==1) bz[a[i]]=0;
                // cnt[d[pp].val]--;
                bz[d[pp].val]=0;
                pp--;
            }
            // if(d[pp].val==a[i]) pp--;
            pp--;
            // cout<<"bz[a[i]]=1 ,pp= "<<pp<<" "<<"\n";
        }
        // else{
        //     bz[a[i]]=1;
        //     // ... ans[]=1;
        // }
        bz[a[i]]=1;
        pp++;
        d[pp].val=a[i];
        // cnt[d[pp].val]++;

        // cout<<"pp= "<<pp<<", m= "<<m<<"\n";
        for(int j=pp;j;j--) ans[d[j].val]++;// ,cout<<d[j].val<<" ";cout<<"\n";
        // cout<<"ans[1]="<<ans[1]<<"\n";
        // cout<<"\n\n";
    }

    printf("%d",ans[1]);
    for(int i=2;i<=m;i++) printf(" %d",ans[i]);putchar('\n');
	return 0;
}

*/
