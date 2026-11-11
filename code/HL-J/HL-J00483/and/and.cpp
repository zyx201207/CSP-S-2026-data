#include <bits/stdc++.h>
using namespace std;
int o[20005];
int er(int a){
	int m[50005];
	int cnt=0, x=0;
	while(a>=1){
		m[cnt] = a%2;
		a /= 2;
		cnt++;
	}
	while(cnt>=0){
		x = x*10+m[cnt];
		cnt--;
	}
	
	
	return x;
}

int pf(int a, int b){
	if(b == 0) return 1;
	if(b == 1) return a; 
	int w=1;
	for(int i=1;i<=b;i++){
		w = w*a;
	}
	return w;
}


int aand(int a,int b){
	int x=er(a);
	int y=er(b);
	int t, d, cnt=0;
	int h[50005];
	while(x!=0||y!=0){
		t = x%10;
		d = y%10;
		if(t == d && d==1){
			h[cnt]=1;
			cnt++;
		}else{
			h[cnt]=0;
			cnt++;
		}
	}
	int r=0;
	for(int i=0;i<cnt;i++){
		r += h[i]*pf(2,i);
	}
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, maxn=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> o[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int z = aand(er(o[i]), er(o[j]));
			maxn = max(maxn, z);
		}
	}
	cout << maxn;
	return 0;
}
