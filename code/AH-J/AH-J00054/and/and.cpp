#include<bits/stdc++.h>
using namespace std;
bool p[200005][35],gf[200005];
long long n,m,a[200005],misp,t;
void erl(long long f1,long long f2){
	long long isp=0;
	while(f1>0){
		p[f2][isp]=f1%2;
		isp++;
		f1=f1/2;
	}
	misp=max(misp,isp-1);
	return;
}
long long pey(long long b){
	if(b==0)return 1;
	long long h=1;
	for(int i=1;i<=b;i++)h=h*2;
	return h;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	misp=-1e6;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		erl(a[i],i);
	}
	while(misp>=0){
		long long s=0;
		for(int i=1;i<=n;i++){
			if(p[i][misp]==true and !gf[i]){
				s++;
			}
		}
		if(s>=m){
			t=t+pey(misp);
			for(int i=1;i<=n;i++){
				if(p[i][misp]==false and !gf[i])gf[i]=true;
			}
		}
		misp--;
	}
	cout<<t;
	return 0;
}

