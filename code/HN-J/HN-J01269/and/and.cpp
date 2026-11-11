#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],m,maxx;
bool op[N];
void dfs(int x){
	if(x>n){
//		for(int i=1;i<=n;i++) cout<<op[i]<<' ';
//		cout<<endl;
		int cnt=0,ans=0;
		vector<int> kou;
		for(int i=1;i<=n;i++){
			if(op[i]==1){
				cnt++;
				kou.push_back(a[i]); 
			}
		}
		if(cnt!=m) return;
		ans=kou[0];
		int len=kou.size();
		for(int i=1;i<len;i++) ans&=kou[i];
		maxx=max(maxx,ans);
		return; 
	}
	bool fb[N];
	for(int i=1;i<=n;i++) fb[i]=op[i];
	dfs(x+1);
	op[x]=1;
	dfs(x+1);
	for(int i=1;i<=n;i++) op[i]=fb[i];
	return;
} 
bool pan1(){
	for(int i=1;i<=n;i++){
		int ab=a[i]+1;
		while(ab%2==0) ab/=2;
		if(ab!=1) return 0;
	}
	return 1;
}
bool cmp(int x,int y){
	return x>y;
}
bool pan2(){
	int ab=n;
	while(ab%2==0) ab/=2;
	if(ab!=1) return 0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) return 0;
	} 
	return 1;
} 
bool pan3(){
	for(int i=1;i<=n;i++){
		if(a[i]>4) return 0;
	}
	return 1;
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
		cout<<maxx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n&&i!=j;j++){
				maxx=max(maxx,a[i]&a[j]);
//				cout<<maxx<<' '<<a[i]<<' '<<a[j]<<endl; 
			} 
		}
		cout<<maxx;
	}else if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++) maxx&=a[i];
		cout<<maxx;
	}else if(pan1()){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}else if(pan2()){
		sort(a+1,a+n+1,cmp);
		maxx=a[1];
		for(int i=2;i<=m;i++){
			maxx&=a[i];
		}
		cout<<maxx;
	}else if(pan3()){
		sort(a+1,a+n+1,cmp);
		int cnt,cnt1,cnt2,cnt3,cnt4;
		cnt=cnt1=cnt2=cnt3=cnt4=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
			if(a[i]==1) cnt1++;
			if(a[i]==2) cnt2++;
			if(a[i]==3) cnt3++;
			if(a[i]==4) cnt4++;
		}
		if(cnt4>=m) cout<<4;
		else if(cnt3>=m) cout<<3;
		else if(cnt3+cnt2>=m) cout<<2;
		else if(cnt1+cnt3>=m) cout<<1;
		else cout<<0;
	}else{
		dfs(1);
		cout<<maxx;
	}
	return 0;
}
/*
5 3
31 3 1 15 7
*/ 
