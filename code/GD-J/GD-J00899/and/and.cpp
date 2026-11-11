#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N];
int n,m;
int ans=0;
int s=(1<<31)-1;
void solve1(int x,int k,int i){
	//cout<<x<<" "<<k<<" "<<i<<endl;
	if(k==m){
		ans=max(ans,x);
		//cout<<ans<<endl;
		return;
	}else if(i>n) return;
	
	solve1(x&a[i],k+1,i+1);
	solve1(x,k,i+1);
	
}
int c2[33],b[29];
void solve2(){
	int x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=20;j++){
			x=1<<j;
			if(a[i]&x) c2[j]++;
		}
	}
	int len=0;
	
	for(int j=1;j<=20;j++){
		if(c2[j]==n) ans+=(1<<j);
		if(c2[j]==n-1) b[++len]=(1<<j);
	}
	int maxc=0;
	for(int i=1,c;i<=n;i++){
		c=0;
		for(int j=1;j<=len;j++){
			if(b[j]&a[i]) c+=b[j];
		}
		maxc=max(maxc,c);
	}
	ans+=maxc;
}
bool spA(){
	for(int i=1;i<=n;i++){
		int x=a[i]+1;
		while(x){
			if(x%2==1&&x/2>0) return 0;
			x/=2;
			
		}
	}
	return 1;
}
void solve3(){
	sort(a+1,a+1+n);
	ans=a[m];
}
bool spB(){
	int x=n;
	while(x){
		if(x%2==1&&x/2>0) return 0;
		x/=2;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) return 0;
	}
	return 1;
}
void solve4(){
	int x=n/2;
	while(x){
		//cout<<ans<<endl;
		if(m>x) break;
		else if(m==x){
			ans+=x;
			break;
		}else{
			ans+=x;
		}
		x/=2;
		
	}
}
void read(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	if(n<=20){
		solve1(s,0,1);
	}else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		}else if(m==n){
			for(int i=1;i<=n;i++) ans=ans&a[i];
		}else if(m==2){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					ans=max(ans,a[i]&a[j]);
		}
	}else{
		if(m==n-1){
			solve2();
		}else if(spA()){
			solve3();
		}else if(spB()){
			solve4();
		}
	}
	cout<<ans<<endl;
	return 0;
}
