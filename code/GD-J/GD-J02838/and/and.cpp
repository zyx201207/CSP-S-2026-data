#include<bits/stdc++.h>

#define int ll
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

const int N=200000;
const int MAXV=30;

int n,m;

int a[N+5];

struct trie{
    int l,r;
    int sum;
};
int cnt=0;
trie tre[N*32+5];

void insert(int a){
	int mq=0;
	for(int i=MAXV;i>=0;i--){
		if(a>=(1<<i)){
			tre[mq].sum++;
			if(tre[mq].l==0){
				tre[mq].l=++cnt;
				tre[cnt].l=tre[cnt].r=tre[cnt].sum=0;
			}
			a-=(1<<i);
			mq=tre[mq].l;
		}
		else{
			if(tre[mq].r==0){
				tre[mq].r=++cnt;
				tre[cnt].l=tre[cnt].r=tre[cnt].sum=0;
			}
			mq=tre[mq].r;
		}
	}
}



signed main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	
    cin>>n>>m;
	tre[0].l=tre[0].r=tre[0].sum=0;
    for(int i=1;i<=n;i++) {cin>>a[i];insert(a[i]);} 
    int mq=0,s=0,ans=0,dep=MAXV,w=0;
    while(tre[mq].l!=0||tre[mq].r!=0){
    	s=tre[mq].sum+w;
    	if(s>=m){
    		ans+=(1<<(dep));
    		mq=tre[mq].l;
    		dep--;
		}
		else{
			w+=tre[tre[mq].l].sum;
			mq=tre[mq].r;
			dep--;
		}
	}
	cout<<ans;
	return 0;
}

