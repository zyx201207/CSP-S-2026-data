#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,a[N],ans,cnt[35],maxc,bita[N][35];
bool d2=true;
int read(){
	char c = getchar();
	int k=0;
	while(c>='0'&&c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return k;
}
void print(int x){
	if(x/10!=0)print(x/10);
	putchar((x%10)+'0');
}
int main(){
	ios::sync_with_stdio(false);
	freopen("and.in", "r", stdin);
	freopen("and.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		int a1=a[i],c=1;
		while(a1>0){
			bita[i][c]=a1%2;
			if(bita[i][c])cnt[c]++,maxc=max(maxc,c);
			c++,a1/=2;
		}
		if(a[i]!=i-1)d2=false;
	}
	if(d2){
		ans=a[n];
		for(int i=n-1;i>n-m;i--){
			ans&=a[i];
		}
		print(ans);
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=maxc;j>=1;j--){
			if(bita[i][j]==1&&cnt[j]<m)a[i]-=(1<<(j-1));
		}
	}
	sort(a+1,a+1+n,greater<int>());
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	print(ans);
}
