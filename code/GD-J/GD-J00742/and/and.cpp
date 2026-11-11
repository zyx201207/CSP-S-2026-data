#include<iostream>
#include<algorithm>
#define F(i,x,y) for(int i=x;i<=y;i++)
#define F2(i,x,y) for(int i=x;i>=y;i--)
#define f(x,y) for(auto x:y)
#define lt(x) x&-x
#define d2(l,r) l+r>>1
#define ls(i) i<<1
#define rs(i) i<<1|1
using namespace std;
const int N=2e5+15;
int n,m,a[N];
int res[32];
void ch2(int x){
	int t[32],j=0;
	while(x){
		t[j]=(x&1);
		++j;
		x>>=1;
	}
	F(i,0,j-1){
		if(t[i]) res[i]++;
	}
}
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	F(i,1,n){
		cin>>a[i];
		ch2(a[i]);
	} 
	int ans=0;
	bool flag=0;
	F2(j,30,0){
		ans*=2;
		if(res[j]>=m){
			if(!flag){
				F(i,1,n){
					if(a[i]&(1<<j)) vis[i]=1;
				}
				ans++;
				flag=1;
			}else{
				int cnt=0;
				F(i,1,n){
					if((a[i]&(1<<j))&&vis[i]) cnt++;
				}
				if(cnt>=m){
					ans++;
					F(i,1,n){
						if((a[i]&(1<<j))&&vis[i]) vis[i]=1;
						else vis[i]=0;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
