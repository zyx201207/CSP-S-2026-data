#include<bits/stdc++.h>
using namespace std;
long long m,n;
struct stairaddoil{
	long long a;
	long long cj=0;
	bool flag=false;
}b[500010];
bool cmd(stairaddoil st1,stairaddoil st2){
	return st1.cj<st2.cj;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> b[i].a;
	long long maxn=-1;
	for(int i=1;i<=n;i++){
		long long stair=0;
		stair=b[i].a;
		for(int j=1;j<=n;j++){
			if(b[j].a<stair){
				b[j].flag=true;
				b[j].cj=stair-b[j].a;
			}
		}
		sort(b+2,b+1+n,cmd);
		long long useful=0;
		for(int j=1;j<=n;j++){
			if(b[j].flag&&m>=b[j].cj){
				m=m-b[j].cj;
				b[j].a=stair;
				useful++;
			}else if(b[j].a==stair) useful++;
		}
		maxn=max(useful,maxn);
	}
	cout << maxn;
}
