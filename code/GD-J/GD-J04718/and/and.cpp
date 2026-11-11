#include<bits/stdc++.h>
#define int ll
#define inf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=1000010;

int n,m,idx;
int f[N],cnt[N];
struct node{
	int id,x;
}a[N];
int cou(int x){
	int cnt=0;
	while(x){
		cnt++;
		x-=(x&(-x));
	}
	return cnt;
}
bool cmp(node a,node b){if((a.x&(1<<idx))!=(b.x&(1<<idx)))return (a.x&(1<<idx))>(b.x&(1<<idx));return a.x>b.x;}
bool cmp2(node a,node b){return cou(a.x)>cou(b.x);}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	
	for(idx=30;idx>=0;idx--){
		if(m<=0)break;
		sort(a+1,a+n+1,cmp);
		queue<int>q;
		int ned=2-cnt[idx];
		for(int i=1;i<=n;i++){
			if(!ned||!m||!(a[i].x&(1<<idx)))break;
			if(f[a[i].id])continue;
			
			ned--;m--;
			f[a[i].id]=1;
			q.push(a[i].id);
//			cout<<a[i].id<<" "<<a[i].x<<endl;
			for(int k=30;k>=0;k--){
				if((a[i].x&(1<<k)))cnt[k]++;
				else cnt[k]=0;
			}
		}
		if(ned>0){
			m+=(2-cnt[idx]);
			while(!q.empty()){
				int gg=q.front();
				q.pop();
				f[a[gg].id]=0;
				for(int k=30;k>=0;k--){
					if((a[gg].x&(1<<k)))cnt[k]--;
				}
			}
		}
		else{
			while(!q.empty()){
				int gg=q.front();
				q.pop();
				for(int k=30;k>=0;k--){
					if(!(a[gg].x&(1<<k)))cnt[k]=0;
				}
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<=30;i++){
		if(cnt[i]>=2)ans|=(1<<i);
	}
	sort(a+1,a+n+1,cmp2);
	int i=0;
	while(m>0){
		i++;
		
		if(!f[a[i].id]){
			ans&=a[i].x;
			m--;
		}
	}
	cout<<ans<<endl;
    return 0;
}
