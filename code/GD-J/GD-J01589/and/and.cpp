#include<bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;

#define mkp make_pair
#define PII pair<int,int>

using namespace std;

const int N=2e5+10;
const int WS=30+5;

int n,m;
int a[N];
bool cmp(int x,int y){
    return x>y;
}

int mxpos;

int b[N][WS];
void split(int pos){
    int num=a[pos];
    // for(int i=29,j=536870912;i;i--,j/=2){
    //     if(num>=j) num-=j,b[pos][i]=1;
    // }
    for(int i=29;~i;i--){
        if(num>=(1<<i)) num^=(1<<i),b[pos][i]=1;
    }
    return;
}

int find(int x,int r){
    int l=1,res=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(b[mid][x]) l=mid+1,res=mid;
        else r=mid-1;
    }
    return res;
}
int ans;

int main(){
	freopen("and.in","r",stdin);
	// freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
	
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        split(i);
    }

    mxpos=n;
    // for(int i=1;i<=n;i++){
    //     for(int j=6;~j;j--) cout<<b[i][j]<<" ";putchar('\n');
    // }
    for(int i=29;~i;i--){
        // int res=find(i,mxpos);
        int cnt=0,lst=0;
        for(int j=1;j<=mxpos;j++){
            if(b[j][i]) cnt++,lst=j;
        }
        if(cnt>=m) ans|=(1<<i),mxpos=min(mxpos,lst);
    }
    printf("%d\n",ans);
	return 0;
}
