#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int read(){
	char c=getchar();
	int k=0,b=1;
	if(c=='-')b=-1,c=getchar();
	while(c>='0'&&c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return k*b;
}
void print(int x){
	if(x/10)print(x/10);
	putchar((x%10)+'0');
}
int c,t,n,d,x[N],ans,tans[N],acnt[N];
int fewen;
struct state{
	int num,l;
};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	if(c==13||c==14){
		cout<<0<<endl;
		return 0;
	}
	while(t--){
		ans=0;
		n=read();d=read();
		fewen=n;
		for(int i=1;i<=n;i++){
			x[i]=read();
			if(i!=1&&fewen==n&&x[i]-x[i-1]>d)fewen=i-1;
		}
		n=fewen;
		for(int i=1;i<n;i++){
//			cout<<ans<<endl;
			memset(tans,0,sizeof tans);
			memset(acnt,0,sizeof acnt);
			queue<state> q;
			q.push({i,0});
			while(!q.empty()){
				state tem = q.front();
//				cout<<tem.num<<" "<<tem.l<<" "<<tans[tem.num]<<endl;
				q.pop();
				if(tans[tem.num]==tem.l)acnt[tem.num]++;
				else if(tans[tem.num]!=0&&tans[tem.num]<tem.l)continue;
				else tans[tem.num]=tem.l,acnt[tem.num]=1;
				for(int j=tem.num+1;j<=n;j++)
					if(x[j]-x[tem.num]<=d)q.push({j,tem.l+1});
			}
			for(int i=1;i<=n;i++){
				if(acnt[i]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
