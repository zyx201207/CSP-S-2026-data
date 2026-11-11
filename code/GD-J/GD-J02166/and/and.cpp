#include<bits/stdc++.h>
using namespace std;
int n,a[200001],m,s,t,C[1025][1025],l[1025];
void dfs(int x,int d,int s){
	if(d>m){
		t=max(t,s);
		return;
	}
	if(x>n) return;
	dfs(x+1,d+1,s&a[x]);
	dfs(x+1,d,s);
}
bool c(){
	for(int i=1;i<=n;i++){
		int p=0;
		for(int j=0;j<30;j++) if(((a[i]>>j)&1)&&(!((a[i]>>(j+1))&1))) p=j;
		if(a[i]>(1<<(p+1)-1)) return 0;
	}
	return 1;
}
bool g(){
	for(int i=1;i<=n;i++) if(a[i]!=i-1) return 0;
	return 1;
}
int main(){
	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	if(n<=20) dfs(1,1,(1<<30)-1);
	else if(n<=2000){
		if(m==1) for(int i=1;i<=n;i++) t=max(t,a[i]);
		else if(m==2) for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) t=max(t,a[i]&a[j]);
		else if(m==n){
			t=(1<<30)-1;
			for(int i=1;i<=n;i++) t&=a[i];
		}
	}else if(m==n-1){
		for(int j=0;j<30;j++){
			int k=0,f=0;
			for(int i=1;i<=n;i++) if((a[i]>>j)&1) k++,f=i;
			if(k==1){
				t=(1<<30)-1;
				for(int i=1;i<=n;i++) if(i!=f) t&=a[i];
				break;
			}
		}
	}else{
		if(c()||g()){
			t=(1<<30)-1;
			sort(a+1,a+1+n,greater<int>());
			for(int i=1;i<=m;i++) t&=a[i];
		}else{
			for(int i=1;i<=n;i++) l[a[i]]++;
			C[1][1]=1;
			for(int i=1;i<=1024;i++){
				int s=0;
				C[i][i]=C[i][1]=1;
				for(int j=2;j<i;j++){
					C[i][j]=C[i-1][j-1]^C[i-1][j];
					if(C[i][j]) s+=l[1024-j];
				}
				if(s>=m){
					t=1024-i+1;
					break;
				}
			}
		}
	}
	cout<<t;
}
