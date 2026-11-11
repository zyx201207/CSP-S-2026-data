#include <bits/stdc++.h> 
#define ll long long
using namespace std;

inline ll read(){
	ll r=0, sgn=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') sgn=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		r=r*10+ch-'0';
		ch=getchar();
	}
	return r*sgn;
}

const ll N=5e5 + 5, M=1e18 + 18, INF=0x3f3f3f3f;
ll n, m, a[N], step;
bool is_dc = true;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n=read(), m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	sort(a+1, a+n+1);
	if(n==1){
		cout << 1;
		return 0;
	}
	
	step=a[2]-a[1];
	if(n==2){
		if(m<=step){
			cout << 2;
		}else{
			cout << 1;
		}
		return 0;
	}
	for(int i=3; i<=n; i++){
		if(a[i]-a[i-1] != step){
			is_dc = false;
			break;
		}
	}
	if(is_dc){
		if(m==0){
			cout << 1;
		}else{
			ll l=0, r=sqrt((m/step)<<1), mid, cur;
			while(l<=r){
				mid = (l+r)>>1;
				cur=((mid)*(mid+1) >> 1)*step;
				if(cur <= m) l=mid+1;
				else r=mid-1;
			}
			cout << min(l, n);
		}
		return 0;
	}else{
		ll ans=0;
		for(int t=1; t<=n; t++){
			ll sd=0, cnt=0; // sum of nearest dists
			int i=t-1, j=t+1;
			// 最后退出时的cnt为第一次sd超过m时加上中心的点数量
			while(sd<=m){ // 双指针贪心求合法选择点数最大值 
				if(i<1){ //左指针先越界 
					while(sd<=m){// 左边无点可选，只能一路右推 
						if(j>n){ //上一次选到了最右边的点 
							cnt++;
							break;
						}
						sd += a[j] - a[t];
						cnt++, j++; //选完j这个点后j右移一位
						// 如果某次循环开始时不满足sd<=m，说明上次选择之后sd已经超过了m，上一次选择非法 
						// 故去中心点数应为cnt-1，带中心点数应为cnt 
						// 但如果是因为j越界退出，则上一次选择是合法的 ，去中心点数应为cnt，带中心点数应为cnt+1 
					}
				}else if(j>n){ //右指针先越界 
					while(sd<=m){ //右边无点可选，只能一路左推 
						if(i<1){// 上一次选到了最左边的点 
							cnt++;
							break;
						}
						sd += a[t] - a[i];
						cnt++, i--;
					}
				}else{
					ll sl=a[t]-a[i], sr=a[j]-a[t];
					if(sl<sr){ //左边更近 
						sd += sl;
						cnt++, i--;
					}else{ //一样近或右边更近 
						sd += sr;
						cnt++, j++;
					}
				}
			}
			ans = max(ans, cnt);
		}
		cout << ans;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
