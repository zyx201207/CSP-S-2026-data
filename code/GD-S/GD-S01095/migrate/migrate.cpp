#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace IO{
	template<typename T>void read(T &x){short f=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();x*=f;return;}
	template<typename T>void out_(T x){if(x>9) out_(x/10);putchar(x%10+'0');return;}
	template<typename T>void out(T x){if(x<0) putchar('-'),x=-x;out_(x),putchar(' ');return;}
	void endl(){putchar('\n');return;}
}using namespace IO;
char st;
const int N=2e6+5,inf=9e18,mod=998244353;
int Tid,T,n,d,a[N],f[5005][5005],g[5005][5005],val1[N],val2[N];
deque<pair<int,int>>stk[N]; //相同的存起来 
int nums[N]; //维护方案 
char ed;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cerr<<"Memory:"<<(&st-&ed)/1048576.0<<"MB"<<endl;
	read(Tid),read(T);
	while(T--){
		read(n),read(d);
		for(int i=1;i<=n;i++) read(a[i]);
		if(n<=5000){ //40pts
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) f[i][j]=inf,g[i][j]=0,stk[j].clear(),nums[j]=0;
				f[i][i]=0,g[i][i]=1;
				//单调队列
				int head=1,tail=0;
				++tail;
				nums[tail]=1;
				stk[tail].push_back(make_pair(i,1));
				for(int j=i+1;j<=n;j++){
					while(head<=tail){
						if((int)stk[head].size()==0) head++;
						else if(a[j]-a[(stk[head].front()).first]>d){
							nums[head]=(nums[head]-(stk[head].front()).second+mod)%mod;
							stk[head].pop_front();
						}
						else break;
					} 
					if(head<=tail){
						f[i][j]=f[i][(stk[head].front()).first]+1;
						g[i][j]=nums[head];
					}
					else break;
					while(head<=tail){
						if((int)stk[tail].size()==0) tail--;
						else if(f[i][(stk[tail].back()).first]==f[i][j]){
							nums[tail]=(nums[tail]+g[i][j])%mod;
							stk[tail].push_back(make_pair(j,g[i][j]));
							break;
						}
						else{
							++tail;
							nums[tail]=g[i][j];
							stk[tail].push_back(make_pair(j,g[i][j]));
							break;
						}
					}
					if(g[i][j]==2) ans++;
				}
			}
			out_(ans),endl();
		}
		else if(Tid>=11&&Tid<=12){
			for(int i=1;i<=n;i++) val1[i]=val2[i]=0;
			for(int i=1;i<=n;i++){
				int l=i+1,r=n,res=i;
				while(l<=r){
					int mid=(l+r)>>1;
					if(a[mid]-a[i]<=d) res=mid,l=mid+1;
					else r=mid-1;
				}
				if(res>i+1) val1[res]++;
			}
			for(int i=1;i<=n;i++){
				int l=1,r=i-1,res=i;
				while(l<=r){
					int mid=(l+r)>>1;
					if(a[i]-a[mid]<=d) res=mid,r=mid-1;
					else l=mid+1;
				}
				if(res<i-1) val2[res]++;
			}
			int res=0;
			for(int i=1;i<n;i++) res+=val2[i]*val1[i+1];
			out(res),endl();
		}
	}
	return 0;
}

//start: 15:34

//start BF

//16:27 40pts n^2

//怎么刻画 (i,j) 的合法性？？？？ 16:36

//18:05 了，只有298啊！！！！快拼点分啊！

//18:09 我会 A 性质了！！！！！ 

//+8!!!!!???真的是对的吗？？ 
 
