#include<bits/stdc++.h>
using namespace std;
int And(int a,int b){
	int i = 1,x = a,y = b,z,h;
	string e,f,c,d,g;
	while(x > 0){
		c += x % 2;
		i++;
	}
	for(int k = 0;k < i;++k){
		e += i - k - 1;
	}
	int j = 1;
	while(y > 0){
		d += y % 2;
		j++;
	}
	for(int k = 0;k < j;++k){
		f += j - k - 1;
	}
	for(int k = 0;k < max(i,j);++k){
		if(e[i] == 1 and f[i] == 1){
			g += '1';
		}else{
			g += '0';
		}
	}
	for(int k = 0;k < g.size();++k){
		h += (g[i] - 32) * pow(2,k);
	}
	return h;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200001];
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;++i){
		scanf("%d",&a[i]);
	}
	sort(a,a + n);
	for(int i = n - 1;i > n - m - 1;--i){
		a[n - 1] = And(a[n - 1],a[i - 1]);
	}
	printf("%d",a[n - 1]);
	return 0;
}
