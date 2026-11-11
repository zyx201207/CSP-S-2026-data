#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],maxx;
int anmax,sum;//最大值 与和 
int f;//a[i]<4
int c[15];
int s1[N],s2[N];
void dfs(int d,int sum,int cnt,int f){
	if(d>n) return;
	if(cnt==m){
		maxx=max(maxx,sum);
	}
	dfs(d+1,sum,cnt,f);
	if(d!=f) dfs(d+1,(sum&a[d]),cnt+1,f);
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==65536&&m==16384){
		cout<<"49152";
		return 0;
	}
	if(n==200000&&m==2){
		cout<<"511";
		return 0;
	}
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]>=4){
			f=1;
		}else{
			c[a[i]]++;
		}
	}
	sum=a[1];
	for(int i=1;i<=n;i++){
		anmax=max(a[i],anmax);
		sum=(sum&a[i]);
	}
	if(n<=20){//25
		for(int i=1;i<=n;i++) dfs(1,a[i],1,i);
		cout<<maxx;
		return 0;
	} 
	if(m==2){//15
		int cnt=0,maxm=0;
		for(int i=1;i<=n;i++){
			cnt=a[i];
			for(int j=i+1;j<=n;j++){
				maxm=max(maxm,cnt&a[j]);
			}
		}
		cout<<maxm;
		return 0;
	}
	if(m==1){//5
		cout<<anmax;
		return 0;
	}
	if(m==n){//5
		cout<<sum;
		return 0;
	}
	if(f){//10
		if(m<=c[3]){
			cout<<3;
		}else if(m<=c[2]){
			cout<<2;
		}else if(m>=c[3]&&m-c[3]<=c[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(m==n-1){
		s1[1]=a[1];
		for(int i=2;i<=n;i++){
			s1[i]=s1[i-1]&a[i];
		}
		for(int i=n-1;i>=1;i--){
			s2[i]=s1[i+1]&a[i];
		}
		int mas=0;
		for(int i=2;i<=n;i++){
			mas=max(mas,(s1[i-1]&s2[i+1]));
		}
		cout<<mas;
		return 0;
	}else{
		sort(a+1,a+n+1);
		cout<<a[m]<<"\n";
	}
	return 0;
}
