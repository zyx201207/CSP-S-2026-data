#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200009];
long long maxx=0;
long long noww=0;
bool tt=1;
long long maxxx=0,maxxxx;
long long aa[18]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
void FindMax(int x,int y){
	int z = noww;
	noww &= a[x];
	if(y==m){
		maxx = max(maxx,noww);
//		cout << noww << endl;
		noww = z;
		return;
	}
	for(int i = x+1;i <= n;i++){
//		printf("Find(%d,%d)\n",i,y+1);
		FindMax(i,y+1);
	}
	noww =z;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		maxxx = max(a[i],maxxx);
		bool nn=0;
		for(int j = 0;!tt&&j <= 16;j++){
			if(a[i]==aa[j]){
				nn=1;
			}
		}
		if(!nn){
			tt=0;
		}
	}
	if(m==1){
		maxxxx = -1;
		for(int i = 1;i <= n;i++){
			maxxxx = max(maxxxx,a[i]);
		}
		cout << maxxxx;
		return 0;
	}
	if(m==n){
		maxxxx = a[1];
		for(int i = 2;i <= n;i++){
			maxxxx &= a[i];
		}
		cout << maxxxx;
		return 0;
	}
	if(tt){
		maxxxx = 2147483647;
		for(int i = 1;i <= n;i++){
			maxxxx = min(maxxxx,a[i]);
		}
		cout << maxxxx;
		return 0;
	}
	if(maxxx < 4){
		sort(a+1,a+n+1);
		maxxxx = a[1];
		for(int i = 2;i <= m;i++){
			maxxxx &= a[i];
		}
		cout << maxxxx;
		return 0;
	}
	for(int i = 1;i <= n+1-m;i++){
		noww = a[i];
		FindMax(i,1);
	}
	printf("%lld",maxx);
	return 0;
}
