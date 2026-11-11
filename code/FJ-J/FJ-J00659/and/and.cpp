#include <bits/stdc++.h>
using namespace std;

int n,m,sum;
long long a[200005],b,ans;
bool num[200005][35],flag[200005];

int read(){
	int k = 0,f = 1,c = getchar();
	for(;!isdigit(c);c = getchar())
		if(c == '-')
			f = -1;
	for(;isdigit(c);c = getchar())
		k = k*10 + (c^48);
	return k * f;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		b = a[i] = read();
		for(int j = 1;j <= 30;j++){
			if(b >= (1<<(30-j))){
				num[i][j] = true;
				b -= (1<<(30-j));
			}
		}
	}
	for(int i = 1;i <= 30;i++){
		sum = 0;
		for(int j = 1;j <= n;j++)
			if(!flag[j] && num[j][i])
				sum++;
		if(sum >= m){
			ans += (1<<(30-i));
			for(int j = 1;j <= n;j++)
				if(!num[j][i])
					flag[j] = true;
		}
	}
	cout << ans;
		
	return 0;
}
