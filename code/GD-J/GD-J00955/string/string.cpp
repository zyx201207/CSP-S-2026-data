#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,cnt;
int a[200005];
char c[200005];
void p1(){
	cnt=0;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		scanf("%d %c",&x,&y);
		for(int j=1;j<=x;j++){
			c[++cnt]=y;
		}
	}
	for(int i=1;i<=cnt/2;i++){
		if(c[i]!=c[cnt-i+1]){
			ans++;
		}
	}
	cout<<ans;
}
void p2(){
	cnt=0;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		a[++cnt]=x;
		c[cnt]=y;
	}
	int hd=1,tl=cnt;
	long long f1=0;
	long long f2=0;
	while(hd<=tl){
		f1+=a[hd];
		f2+=a[tl];
		if(f1<=f2){
			if(c[hd]!=c[tl]){
				ans+=f1;
			}
			f1-=f1;
			f2-=f2;
		}else{
			if(c[hd]!=c[tl]){
				ans+=f2;
			}
			f1-=f2;
			f2-=f2;
		}
		hd++;
		tl--;
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	scanf("%d",&n);
	if(n<=2000){
		p1();
	}else{
		p2();
	}
	return 0; 
}
