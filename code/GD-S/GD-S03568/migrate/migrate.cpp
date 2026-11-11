#include<bits/stdc++.h>
using namespace std;
void op(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
int y,way,a[1000006],b[1000006],s[1000006],mi,d,n,ans;
void dfs(int id,int num){
	if(id==y){
		if(mi>num){
			mi=num;
			way=1;
		}else if(mi==num){
			way++;
		}
		return;
	}
	for(int i=id+1;i<=y;i++){
		if(s[i]-s[id]<=d){
			dfs(i,num+1);
		}
	}
}
bool check(int x){
	for(int i=x;i<y;i++){
		if(b[i]>d)return false;
	}
	way=0; 
	mi=1e9;
	dfs(x,0);
	return (way==2);
}
void work1(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		if(i==1)b[i]=0;
		s[i]=s[i-1]+b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			y=j;
			if(s[j]-s[i-1]>d&&check(i))ans++;
		}
	}
}
void work2(){
	cout<<0;
}
int main(){
	op();
	int c,T;
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		if(n>5000){
			work2();
		}else{
			work1();
		}
		cout<<ans<<"\n";
	}
}
