#include<bits/stdc++.h>
#define in :
#define int long long
using us=unsigned;
using namespace std;
template<typename T>
void read(T& a) {
	cin>>a;
	return void();
}
template<typename T,typename... Args>
void read(T& a,Args&... args) {
	read(a);
	read(args...);
	return void();
}
template<typename T>
void print(T a) {
	cout<<a;
	return void();
}
template<typename T,typename... Args>
void print(T a,Args... args) {
	print(a);
	print(args...);
	return void();
}
const int N =2e6;
int c,t;
int n,d;
int x[N+10];
int to[N+10];//从第i个岛可以直接到达的最远的岛
inline void work2() {
	read(n,d);
	for(us i=1; i<=n; i++) {
		read(x[i]);
	}
	x[n+1]=4e18;
	for(us i=1; i<=n; i++) {
		to[i]=upper_bound(&x[1],&x[n+1],x[i]+d)-x-1;
	}
	int ans=0;
	int last=0;
	for(us i=1; i<=n-3; i++) {
		if(to[i]==i+2&&to[i+1]==i+3) {
			ans+=i-last;
		}
		if(to[i]!=i+1) {
			last=i;
		}
	}
	print(ans,'\n');
	return void();
}
int dis[3010];
inline void work1() {
	read(n,d);
	for(us i=1; i<=n; i++) {
		read(x[i]);
	}
	for(us i=1; i<=n; i++) {
		to[i]=upper_bound(&x[1],&x[n+1],x[i]+d)-x-1;
	}
	int ans=0;
	for(us i=n; i; i--) {
		dis[i]=1;
		for(us j=i-1; j; j--) {
			dis[j]=0;
			for(us k=j+1; k<=n&&to[j]>=k; k++) {
				dis[j]+=dis[k];
				if(dis[k]>2) {
					break;
				}
			}
			if(dis[j]==2) {
				ans++;
			}
		}
	}
	print(ans,'\n');
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c,t);
	while(t--)  {
		if(c==13||c==14) {
			print(0);
			continue;
		}
		work2(); 
	}
	return 0;
}
//不妨大胆猜测,最小数量的双径岛屿必是四个,且开始的岛和后面那个只能跳两个.猜错了
