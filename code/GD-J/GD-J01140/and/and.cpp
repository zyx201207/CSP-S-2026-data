#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
vector<int> G[40];
long long a[maxn];
int b[maxn];
long long num;
bool ok;
void f(int cnt){
	int c[41];
	for(int i=1;i<=40;i++) c[i]=0;
	for(auto i:G[cnt]){
		int ans=0;
		for(;pow(2,ans)<=a[i];ans++){
			int x=a[i];
			x/=pow(2,ans);
			x%=2;
			c[ans+1]+=x;
		}
		b[i]=ans-1;
	}
	for(int i=40;i>=1;i--){
		if(c[i]>=m){
			ok=true;
			num+=pow(2,i-1);
			for(auto j:G[cnt]){
				if(i==b[j]+1){
				    G[cnt+1].push_back(j);
				    a[j]-=pow(2,i-1);
			    }
			}
			break;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) G[1].push_back(a[i]);
	ok=true;
	for(int i=1;ok==true;i++){
		ok=false;
		f(i);
	}
	cout<<num;
	return 0;
}
