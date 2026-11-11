#include<bits/stdc++.h>
using namespace std;
long long n,m,x,s,t,a[200005][35],ans;
bool f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x,t=30;
		while(t)
			a[i][t]=x%2,x/=2,t--;
	}
	for(int i=1;i<=30;i++){
		t=0;
		for(int j=1;j<=n;j++)
			if(!f[j]) t+=a[j][i];
		if(t>=m)
			for(int j=1;j<=n;j++)
				if(!f[j]) f[j]=1-a[j][i];
	}
	t=1;
	for(int i=30;i>1;i--){
		s=1;
		for(int j=1;j<=n;j++)
			if(!f[j]) s&=a[j][i];
		ans+=s*t,t*=2;
	}
	cout<<ans;

	return 0;
} 
