#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e5+10;

int n,m;
int a[maxn],ans;

vector<int>tmp;
void dfs(int u,int cnt,int choose,vector<int>q){
	if (u>n+1)return;
//	printf("[debug]u=%lld cnt=%lld choose=%lld\n",u,cnt,choose);
	if ((choose>=m||u==n+1)&&choose>=m){
		if (cnt>ans){
			ans=cnt;
			tmp=q;
		}
	}
	dfs(u+1,cnt,choose,q);
	if (choose==0){
		q.push_back(a[u]);
		dfs(u+1,a[u],choose+1,q);
	}
	if (choose+1<=m){
		q.push_back(a[u]);
		dfs(u+1,cnt&a[u],choose+1,q);
	}
	return;
}

void work1(){
	vector<int>null;
	dfs(1,0,0,null);
	for (int i=0;i<tmp.size();++i)cout<<tmp[i]<<' ';
	cout<<endl;
	return;
}
void work2(){
	for (int i=1;i<=n;++i){
		ans=max(ans,a[i]);
	}
	return;
}
void work3(){
	ans=a[1];
	for (int i=2;i<=n;++i){
		ans&=a[i];
	}
	return;
}
void work4(){
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (i==j)continue;
			ans=max(ans,a[i]&a[j]);
		}
	}
	return;
}
void work5(){
	//不去与最糟糕的 
	//不去与2^x中的最小的 
	int dont=0;
	for (int i=1;i<=n;++i){
		if (a[i]==2||a[i]==4||a[i]==8||a[i]==16||a[i]==32||a[i]==64||a[i]==128||a[i]==256||a[i]==512||a[i]==1024||a[i]==2048||a[i]==4096||a[i]==8192||a[i]==16384||a[i]==32768||a[i]==65536||a[i]==131072||a[i]==262144||a[i]==524288||a[i]==1048576||a[i]==2097152||a[i]==4194304){
			if (a[i]<a[dont])dont=i;
		}
	}//&有交换律 
	int cnt=a[1];
	for (int i=1;i<=n;++i){
		if (i==dont)continue;
		cnt&=a[i];
	}
	ans=cnt;
	return ;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	freopen("and4.in","r",stdin);
//	freopen("and4.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	if (n<=20&&m<=n){
		work1(); 
	}
	else if (n<=2000){
		if (m==1){
			work2();
		}
		else if (m==n){
			work3();
		}
		else if (m==2){
			work4();
		}
	}
	else {
		if (m==n-1){
			work5();
		}
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

6 4
6 5 3 7 11 0
*/
