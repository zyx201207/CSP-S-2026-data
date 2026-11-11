#include <bits/stdc++.h>
using namespace std;
template <typename type>
void read(type &val){
	bool flag=false;
	val=0;
	char ch=getchar();
	while(ch<'0'||'9'<ch){
		if(ch=='-')
			flag=true;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		val=val*10+(ch-'0');
		ch=getchar();
	}
	if(flag)
		val=-val;
}
template <typename type>
void write(type val){
	int top=0;
	static char __dights[32];
	do{
		__dights[++top]=val%10+'0';
		val/=10;
	}while(val);
	while(top)
		putchar(__dights[top--]);
}
using ll=long long;
namespace Case1{
	const int maxN=5e3; 
	int n,ans,f[maxN+5],s[2];
	ll d,a[maxN+5];
	queue<int> q[2];
	void solve(){
		ans=0;
		read(n),read(d);
		for(int i=1;i<=n;i++)
			read(a[i]);
		for(int l=1;l<=n;l++){
			s[0]=s[1]=0; 
			while(!q[0].empty())
				q[0].pop();
			while(!q[1].empty())
				q[1].pop();
			f[l]=s[0]=1;
			q[0].push(l);
			for(int r=l+1;r<=n;r++){
				if(a[r]-a[r-1]>d)
					break;
				while(!q[0].empty()&&a[r]-a[q[0].front()]>d){
					s[0]-=f[q[0].front()];
					q[0].pop();
				}
				if(!s[0]){
					swap(s[0],s[1]);
					swap(q[0],q[1]);
					while(!q[0].empty()&&a[r]-a[q[0].front()]>d){
						s[0]-=f[q[0].front()];
						q[0].pop();
					}
				}
				f[r]=min(s[0],3);
				s[1]+=f[r];
				q[1].push(r);
				ans+=(f[r]==2);				
//				printf("%d ",f[r]);
			}
//			printf("\n");
		}
		write(ans);
		putchar(10);
	}
	void _main(){
		int T;
		read(T);
		for(;T;T--) solve();
	} 
}
namespace Case2{
	const int maxN=2e6; 
	int n,f[maxN+5],s[2];
	ll d,ans,a[maxN+5];
	queue<int> q[2];
	void solve(){
		ans=0;
		read(n),read(d);
		for(int i=1;i<=n;i++)
			read(a[i]);
		for(int l=1;l<=1;l++){
			s[0]=s[1]=0; 
			while(!q[0].empty())
				q[0].pop();
			while(!q[1].empty())
				q[1].pop();
			f[l]=s[0]=1;
			q[0].push(l);
			for(int r=l+1;r<=n;r++){
				if(a[r]-a[r-1]>d)
					break;
				while(!q[0].empty()&&a[r]-a[q[0].front()]>d){
					s[0]-=f[q[0].front()];
					q[0].pop();
				}
				if(!s[0]){
					swap(s[0],s[1]);
					swap(q[0],q[1]);
					while(!q[0].empty()&&a[r]-a[q[0].front()]>d){
						s[0]-=f[q[0].front()];
						q[0].pop();
					}
				}
				f[r]=min(s[0],3);
				s[1]+=f[r];
				q[1].push(r);
				ans+=(f[r]==2)*(n-r+1);				
//				printf("%d ",f[r]);
			}
//			printf("\n");
		}
		write(ans);
		putchar(10);
	}
	void _main(){
		int T;
		read(T);
		for(;T;T--) solve();		
	}
}
namespace Case3{
	const int maxN=2e6; 
	int n;
	ll d,ans,a[maxN+5];
	void solve(){
		ans=0;
		read(n),read(d);
		for(int i=1;i<=n;i++)
			read(a[i]);
		for(int i=1;i<=n;i++){
			int last=i;
			for(int pw=(1<<20);pw;pw/=2){
				int last_=last+pw;
				if(last_>n)
					continue;
				if(a[last_]-a[i]<=d)
					last=last_; 
			}
			if(last==n)
				break;
			if(a[last+1]-a[last]>d)
				continue;
			int last3=last;
			if(last-i>=3){
				for(int pw=(1<<20);pw;pw/=2){
					int last3_=last3+pw;
					if(last3_>n)
						continue;
					if(a[last3_]-a[last-2]<=d)
						last3=last3_; 
				}				
			}
			int last2=last;
			if(last-i>=2){
				for(int pw=(1<<20);pw;pw/=2){
					int last2_=last2+pw;
					if(last2_>n)
						continue;
					if(a[last2_]-a[last-1]<=d)
						last2=last2_; 
				}				
			}
			ans+=last2-last3;
		}
		write(ans);
		putchar(10);
	}
	void _main(){
		int T;
		read(T);
		for(;T;T--) solve();		
	}	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int index;
	read(index);
	if(index<=10)
		Case1::_main();
	else if(index<=12)
		Case2::_main();
	else if(index<=14)
		Case3::_main();
}
