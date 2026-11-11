#include<bits/stdc++.h>
using namespace std;

int c, t;
int n;
long long d;
long long x[2000086];
struct P{
	int hd, tl;
};
vector<P> v;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%lld", &n, &d);
		int ans = 0;
//		int pr = 0;
//		int bk = 0;
//		int lst = 1;
		v.clear();
		for(int i = 1; i <= n; i++){
			scanf("%lld", &x[i]);
		}
		x[n+1] = x[n] + d + 100;
		int hd=1, tl=4;
		while(hd<n){
			while(tl-hd<3) tl++;
			while(tl>n){
				tl--;
				hd++;
			}
			
//			printf("#%d %d\n",hd, tl);
			//check hd~tl
			if(x[tl]-x[hd]<2ll*d&&x[tl]-x[hd]>d){
				int tmp1=0;
				int tmp2=0;
				for(int i = hd; i <= tl; i++){
					if(x[i]-x[hd]<=d){
						tmp1=i;
					}else{
						break;
					}
				}
//				printf("^%d %d\n", tmp1, tmp2);
//				printf("^%d %d\n", hd, tl);
				for(int i = tl; i >= hd; i--){
					if(x[tl]-x[i]<=d){
						tmp2=i;
					}else{
						break;
					}
				}
				if(tmp1-tmp2==1){
					v.push_back({hd,tl});
					tl++;
				}else if(tmp1 == tmp2){
					hd++;
					tl=hd;
				}else{
					tl++;
				}
			//check finish
			}else if(x[tl]-x[hd]>=2ll*d){
				hd++;
				tl=hd;
			}else{
				tl++;
			}
		}
		v.push_back({n,n});
		
//		for(int i = 0; i < v.size(); i++){
//			printf("*%d %d\n", v[i].hd, v[i].tl);
		}
		
		
		int lst = 1, nx;
		for(int i = 0; i<v.size()-1; i++){
			for(int j = v[i].hd; j>=lst; j--){
				if(x[j] - x[j-1] > d){
					lst = j;
					break;
				}
			}
			int k = i + 1;
			while(v[k].tl==v[i].tl)k++;
			nx = v[k].hd;
			for(int j = v[i].tl; j<=v[i+1].hd; j++){
				if(x[j+1] - x[j] > d){
					nx = j;
					break;
				}
			}
			ans+=max(1,v[i].hd-lst+1)*max(1,nx-v[i].tl+1);
//			printf("!%d %d %d %d\n", lst, v[i].hd, v[i].tl, nx);
			if(v[i+1].hd!=v[i].hd)lst=v[i].tl;
		}
//		for(int i = 4; i <= n; i++){
//			if(x[i] - x[i-3] > d && x[i] - x[i-2] <= d && x[i-1] - x[i-3] <= d){
//				s.push(i);
//			}
//		}
//		s.push(n+3);
//		while(!s.empty()){
//			pr = s.front();
//			for(int i = pr-3; i >= lst; i--){
//				if(x[i] - x[i-1] > d){
//					lst = i;
//					break;
//				}
//			}
//			s.pop();
//			if(s.empty())break;
//			bk = s.front();
//			for(int i = pr; i <= bk-3; i++){
//				if(x[i+1] - x[i] > d){
//					bk = i + 3;
//					break;
//				}
//			}
//			ans += max(1,pr-2-lst)*max(1,bk-2-pr);
////			printf("*a%d\n",ans);
////			printf("*b%d\n",ans);
//			lst = pr;
//		}
		printf("%d\n", ans);
	}
	return 0;
}
