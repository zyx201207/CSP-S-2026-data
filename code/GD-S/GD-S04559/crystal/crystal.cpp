#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+9;
int n,m,ans=1,t1=N,wz;
struct s{
	int w,c;
	bool l=1;
}b[N];
int a[N],t[N],s[N];
/*int twof(int l,int r){
	if(l<1||r>n||l>=r){
		return 0;
	}
	int t,t1,t2;
	int mid=(l+r)/2;
	for(int i=l;i<=r;i++){
		t+=b[i];//区间差值和 
 }
	t1=twof(l,mid);
	t2=twof(mid+1,r);
	ans=min(t1,t2);
	return t;
}//最小区间差值和*/
void update(int l,int x){
	for(int i=l;i<=n;i++){
		s[i]-=x;
	}
}
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m){
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			if(a[i]<0){
				b[i].c=a[i]-a[i-1]*-1;
			}
			else b[i].c=a[i]-a[i-1];
			b[i].w=b[i].c;
			t[i]=1;
			//cout<<b[i].w<<" ";
		}
		for(int i=2;i<=n;i++){
			s[i]=s[i-1]+b[i].w; //s[i]=b[1]到b[i]的区间和
		}
		for(int i=2;i<=n;i++){
			if(b[i].c==0){
				continue;
			}
			t1=min(t1,b[i].w);
		}
		for(int i=2;i<=n;i++){
			if(b[i].l){
			if(t1==b[i].w){
				update(i,t1);
				b[i].w=s[i]-s[i-1];
				a[i]=a[i-1];
				m-=t1;
				ans++;
				t1=N;
				b[i].l=0;
				break;
			}
		}
		}
	}
	cout<<ans;
	return 0;
} 
