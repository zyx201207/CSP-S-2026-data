#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	char c;
	long long f=1,num=0;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+(c-'0');
		c=getchar();
	}
	return f*num;
}
int num,t,n;
bool same=1;
long long ans,d;
long long Min[5005][5005],c[5005][5005],x[2000006];
void dfsr(int now,int top,int cnt){
	c[now][top]++;
	c[top][now]++;
//	if(c[now][top]>2) return ;
	for(int i=now+1;i<=n;i++){
		if(x[i]-x[now]>d) break;
		if(Min[top][i]<cnt+1) continue;
		dfsr(i,top,cnt+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	cin>>num>>t;
	num=read();
	t=read();
	while(t--){
//		cin>>n>>d;
		n=read();
		d=read();
		for(int i=1;i<=n;i++) x[i]=read();//cin>>x[i];
		if(num<=10){
			for(int i=1;i<=n;i++){
				long long dis=0,cnt=1;
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[j-1]>d) break;
					dis+=x[j]-x[j-1];
					if(dis>d){
						dis=x[j]-x[j-1];
						cnt++;
					}
					Min[i][j]=Min[j][i]=cnt;
				}
			}
			for(int i=1;i<=n;i++) dfsr(i,i,0);
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++) //cout<<i<<' '<<j<<' '<<c[i][j]<<'\n';
					if(c[i][j]==2)
						ans++;
			cout<<ans<<'\n';
			ans=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					c[i][j]=0;
		}
		else if(num>=11&&num<=12){
			long long dis=x[2]-x[1],cnt;
			cnt=d/dis;
//			cout<<cnt<<'\n';
			if(cnt==0||cnt==1) cout<<"0\n";
			else{
//				for(int i=1;i<=n;i++){
//					if(i+cnt+cnt>n) break;
//					ans++;
//				}
				cout<<max(0ll,n-cnt*2+1)<<'\n';
//				ans=0;
			}
		}
	}
}
/*
0 2
5 3
-2 -1 0 1 2
6 2 
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
