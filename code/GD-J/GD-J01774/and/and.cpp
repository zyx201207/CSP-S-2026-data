#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,_ax;
int a[N],b[N][32],c[N],_num[4],q[N],h[N];
void dfs(int _now,int _nu,int _cnt){
	if(_nu==m){
		_ax=max(_ax,_cnt);
		return ;
	}
	for(int i=_now+1;i<=n;i++){
		dfs(i,_nu+1,_cnt&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool fa=1,fb=1;
	cin >> n >> m;
	int _ma=INT_MIN;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		_ma=max(_ma,a[i]);
		int tmp=a[i],now=0;
		while(tmp>0){
			if(tmp%2==0){
				fa=0;
			}
			b[i][++now]=tmp%2;
			tmp>>=1;
		}
		c[i]=now;
		if(a[i]!=i-1){
			fb=0;
		}
	}
	if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout << ans;
	}else if(fa){
		sort(a+1,a+1+n,greater<int>());
		cout << a[n-m+1] << endl;
	}else if(_ma<4){
		for(int i=1;i<=n;i++){
			_num[a[i]]++;
		}
		if(_num[3]>=m){
			cout << 3;
		}else if(_num[3]+_num[2]>=m){
			cout << 2;
		}else if(_num[3]+_num[1]>=m){
			cout << 1;
		}else{
			cout << 0;
		}
	}else if(m==n-1){
		q[1]=a[1];
		for(int i=2;i<=n;i++){
			q[i]=q[i-1]&a[i];
		}
		h[n]=a[n];
		for(int i=n-1;i>=1;i--){
			h[i]=h[i+1]&a[i];
		}
		int _maa=INT_MIN;
		for(int i=1;i<=n;i++){
			if(i==1)_maa=max(_maa,h[i+1]);
			else if(i==n)_maa=max(_maa,q[i-1]);
			else _maa=max(_maa,q[i-1]&h[i+1]);
		}
		cout << _maa;
	}else if(m==1){
		sort(a+1,a+1+n,greater<int>());
		cout << a[1];
	}else if(m==2){
		int _maaa=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				_maaa=max(_maaa,a[i]&a[j]);
			}
		}
		cout << _maaa;
	}else{
		for(int i=1;i<=n-m+1;i++){
			if(a[i]<_ax){
				continue;
			}
			dfs(i,1,a[i]);
		}
		cout << 1 << endl;
		cout << _ax;
	}
	return 0;
} 
