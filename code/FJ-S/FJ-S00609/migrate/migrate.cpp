#include<bits/stdc++.h>
using namespace std;
int _c,t;
int n;
long long d;
long long x[2000010];
long long _in(){
	long long x=0;
	long long f=1;
	char c=getchar();
	while((c<'0'||c>'9')&&(c!='-')){
		c=getchar();
	}
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
long long b[2000010];
int c[2000010];
bool bj[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\migrate\\migrate3.in","r",stdin);
	_c=_in();
	t=_in();
	for(int ___=1;___<=t;___++){
		n=_in();
		d=_in();
		for(int i=1;i<=n;i++){
			x[i]=_in();
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				b[j]=1e18;
				bj[j]=0;
				c[j]=0;
			}
			queue<int> q;
			q.push(i);
			b[i]=0;
			bj[i]=1;
			while(q.size()){
				int u=q.front();
//				cout<<"u="<<u<<"\n";
//				cout<<"b["<<u<<"]="<<b[u]<<"\n";
				q.pop();
				for(int j=1;j<=n;j++){
					if(j==u){
						continue;
					}
					if(abs(x[j]-x[u])>d){
						continue;
					}
					if(bj[j]==0){
						b[j]=b[u]+1;
						bj[j]=1;
						q.push(j);
					}
					if(b[u]+1==b[j]){
						c[j]++;
//						cout<<"c["<<j<<"]="<<c[j]<<"\n";
					}
				}
			}
			for(int j=1;j<=n;j++){
//				cout<<"c["<<j<<"]="<<c[j]<<"\n";
				if(c[j]==2){
					ans++;
				}
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}