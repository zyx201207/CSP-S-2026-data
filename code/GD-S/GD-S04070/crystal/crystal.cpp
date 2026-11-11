#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+(ch-'0');
	return x*f;
}
const int N=5e5+10;
int n,m,a[N];
void work(){
	int ans=1,num=m,k=1;
	for(int i=2;i<=n;i++){
		int cnt=(a[i]-a[i-1])*k;
		k++;
		if(cnt<=num) ans++,num-=cnt;
		else break;
	}
	cout<<ans;
}
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	clock_t start=clock();
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int p=a[2]-a[1],flag=1;
	for(int i=3;i<=n;i++){
		if(a[3]-a[2]!=p){
			flag=0;break;
		}
	}
	if(flag){
		work();
		return 0;
	}
	int ans=1;
	for(int j=1;j<=n;j++){
		int num=m,sum=1,k=1;
		for(int i=j+1;i<=n;i++){
			int cnt=(a[i]-a[i-1])*k;
			k++;
			if(cnt<=num) sum++,num-=cnt;
			else{
				ans=max(ans,sum);
				break;
			}
		}
	}
	cout<<ans;
//	cout<<'\n'<<clock()-start<<"ms";
	return 0;
}
/*
5 5
1 2 4 8 9

3


5 8
-3 -1 2 2 7

4
*/
