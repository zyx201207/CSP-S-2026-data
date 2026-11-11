#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int s[200010];
struct S{
	int to;
	int time;
	int t;
}; 
int dg(int x,int y,int t){
	/*if(x>n||y>m) return 1;
	if(y==m) return t;
	for(int i=x+1;i<=n;i++){
		max1=max(max1,dg(i,y+1,t&a[i]));
	}
	return max1;
	*/
	int max1=0;
	queue<S> q;
	q.push({0,0,1073741823});
	while(!q.empty()){
		int x=q.front().to;
		int y=q.front().time;
		int z=q.front().t;
		q.pop();
		if(y==m){
			max1=max(max1,z);
			continue;
		}
		for(int i=x+1;i<=n;i++){
			q.push({i,y+1,z&a[i]});
		}
	}
	return max1;
}
bool pd(int x){
	if(x==1) return 1;
	while(x%2==0){
		x=x/2;
		if(x==1) return 1;
	}
	return 0;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//首先想到f[i][j]表示前i个取j个的最大值
	//f[i][j]=max(f[i-1][j],a[i]&f[i-1][j-1]);
	//但貌似不是这样的呢
	//暴力吧 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!pd(a[i]+1)) f=0;
	}
	if(m==1){
		int max1=-1e9;
		for(int i=1;i<=n;i++){
			max1=max(max1,a[i]);
		}
		cout<<max1;
		return 0;
	}
	if(m==2){
		int max1=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				max1=max(max1,a[i]&a[j]);
			}
		}
		cout<<max1;
		return 0;
	}
	if(f){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	cout<<dg(0,0,1073741823);//暴力出奇迹 约20分 
	return 0;
}
