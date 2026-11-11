#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
#define M 100005
ll i, j, k, n, m, a[N], u[N], t[N], f, x, y;
ll bu, ok[N*2], okok, ke, s;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		if(!ok[a[i]+M]){
			u[++k]=a[i];//k种
			ok[a[i]+M]++;//判定是否记录 
		}
		t[a[i]+M]++;//同数字出现次数 
	}
	sort(u+1, u+k+1);
//	for(i=1; i<=k; i++){
//		printf("(%lld %lld)", u[i], t[u[i]+M]);
//	} 
	for(i=2; i<=k; i++){
		bu=okok=0, ke=t[u[i]+M];
		for(j=i-1; j>0; j--){
			x=u[i], y=u[j];
			f=t[y+M]*(x-y);//两者之间桶步数 
			if(bu+f<=m){
				bu+=f;
				ke+=t[y+M];
			}
			else{
				while(bu+x-y<=m){
					bu+=x-y;
					ke++;
				}
				okok=1;
			}
			s = ke>s ? ke:s;
			if(okok) break;
		}
	}
	printf("%lld", s);
	return 0;
} 
