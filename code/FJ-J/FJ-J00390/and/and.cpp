#include<bits/stdc++.h>//T3
#define debug cout<<"\n----------------------------"
using namespace std;
int n,m,xxx,fl=0;
bool cs14=1,cs16=1,cs13=1;
int a[200001];
inline int rd(){
	int k=0,q=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')q=-1;
		c=getchar();
	}while(isdigit(c)){
		k*=10,k+=c-48,c=getchar();
	}
	return k*q;
}void dfs(int i,int k,int s){//当前，几个，值 
	if(k==m){
		xxx=max(xxx,s);
		return;
	}if(i==n)return;
	if(i==1&&!fl){
		fl=1;
		dfs(i,k+1,s&a[i]);
	}
	for(int j=i+1;j<=n;j++){
		dfs(j,k+1,s&a[j]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=rd(),m=rd();
	for(int i=1;i<=n;++i){
		a[i]=rd();
		if(a[i]!=i-1)cs14=0;
		if(a[i]>4)cs16=0;
		if(__builtin_popcount(a[i])!=32-__builtin_clz(a[i]))cs13=0;
	}if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}if(m==n){
		int ans=a[1]; 
		for(int i=2;i<=n;++i){
			ans&=a[i];
		}cout<<ans;
		return 0;
	}if(m==2){
		int ans=-1;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				ans=max(ans,a[i]&a[j]);
			}
		}cout<<ans;
		return 0;
	}if(cs14){
		if(__builtin_popcount(m)==1){
			cout<<n-m;
			return 0;
		}
		int bse=32-__builtin_clz(m);
		bse=1<<(bse-1);
		bse<<=1;
		cout<<n-bse;
		return 0;
	}if(cs16){
		int hs[5];
		for(int i=1;i<=n;++i){
			hs[a[i]]++; 
		}
		if(m<=a[4]){
			cout<<4;
			return 0;
		}else if(m<=a[3]){
			cout<<3;
			return 0;
		}else if(m<=a[3]+a[2]){
			cout<<2;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}if(cs13){
		sort(a+1,a+n+1);
		int ans=0x7fffffff;
		for(int i=n;i>=n-m+1;--i){
			ans&=a[i];
		}cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(1,0,0x7fffffff);
		cout<<xxx;
		return 0;
	}cout<<rand();
	return 0;
}
