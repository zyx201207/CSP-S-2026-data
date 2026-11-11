#include<bits/stdc++.h>//9:56finish样例全过
#define int long long
using namespace std;
inline int read(){
	int x(0),sign(1);
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()){
		if(ch=='-'){
			sign=-1;
		}
	}
	for(;isdigit(ch);ch=getchar()){
		x=x*10+ch-'0';
	}
	return x*sign;
}
int n,m;
int a[200005];
bool t2[200005][32];
int k[32];
void cl2(){
	for(int i=1;i<=n;++i){
		for(int j=30;j>=0;--j){
			if((1ll<<j)&a[i]){
				t2[i][j]=1;
				k[j]++;
			}
		}
	}
}
int t,ans;
vector<int> lst;
signed main(){//关注dlc666嘛，b站叫大破车dlc666 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	} 
	cl2();
	for(int i=30;i>=0;--i){
		if(k[i]>=m){
			t=i;
			break;
		}
	}
	for(int i=1;i<=n;++i){
		if(t2[i][t]==1){
			lst.push_back(i);
		}
	}
	ans=(1ll<<t); 
	for(int j=t-1;j>=0;--j){
		vector<int>ok;
		int cnt=0;
		for(int v : lst){
			if(t2[v][j]){
				cnt++;
				ok.push_back(v);
			}
		}
		if(cnt>=m){
			ans+=(1ll<<j);
			lst.clear();
			lst=ok;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
4 2
3 15 12 12
*/
/*
5 3
31 3 1 15 7
*/ 
