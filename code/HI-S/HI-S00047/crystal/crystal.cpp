#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+67;
int n,m,a[N],max1=-1,cnt;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int k){
	if(!k){
		int a1[N]={0};
		for(int i=1;i<=n;i++){
			if(a[i]<0)a1[abs(a[i])]++;
			else a1[a[i]+5001]++;
		}
		sort(a1+1,a1+10003,cmp);
		if(a1[1]>max1)max1=a1[1];
		return ;
	}
	for(int i=1;i<=n;i++){
		a[i]++;
		dfs(k--);
		a[i]--;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int flag=true,galf=true,_=0/*棍木变量名*/;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			_=a[i]-a[i-1];
		}
		if(i>=2){
			if(a[i]-a[i-1]!=1)flag=false;
			if(a[i]-a[i-1]!=_)galf=false;
		}
	}
	if(flag){  //棍木特例A 
		int i=0,cnt=0;
		while(m>=0){
			m=m-i;
			if(m<0)break;
			cnt++;
			i++;
		}
		cout<<cnt;
	}else if(galf){  //棍木特例B 
		int i=0,cnt=0;
		while(m>=0){
			m=m-_;
			if(m<0)break;
			cnt++;
			i+=_;
		}
		cout<<cnt;
	}else if(n<=20){  //棍木深搜  
		dfs(m);
		cout<<max1;
	}else if(n<=100){  //棍木O(n^3)或O(n^4)暴力 (其实有可能连这个都想不出来) 
		//棍木 
	}else if(n<=10000){  //棍木O(n^2)模拟/暴力/枚举/贪心
		//棍木 
	}else{  //棍木瞎搞的正解(并非) 
		//棍木 
	}
}
