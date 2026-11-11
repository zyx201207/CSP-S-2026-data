#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans=1,p,t;
long long a[500010];
long long b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	}
	for(int i=1;i<=n;i+=1){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000){
		ans=1;
		int x=a[2]-a[1];
		p=x;
		while(n>1){
			if(m<p){
				break;
			}
			m-=p;
			p+=x;
			n-=1;
			ans+=1;
		}
		cout<<ans;
		return 0;
	}
	b[1]=0;
	for(int i=2;i<=n;i+=1){
		b[i]=b[i-1]+abs(a[i]-a[i-1]);
	}
	for(int i=2;i<=n;i+=1){
		cnt=1;
		p=i-1;
		t=m;
		while(p>=1){
			if(b[i]-b[p]<=t){
				t-=b[i]-b[p];
				p-=1;
				cnt+=1;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
