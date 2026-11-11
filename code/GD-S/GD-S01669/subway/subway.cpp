#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,t=0,jsq=0;
int plan[100];
struct station{
	int kou;
	int zuo[1000];
	bool sub[10000];
}s[100000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c ;
	for(;c>0;c--){
		cin >> n >> m >> d >> q;
		for(int i=1;i<=m;i++){
			cin >> s[i].kou;
		}
		for(int i=1,k;i<=n;i++){
			cin >> k;
			for(int j;k>0;k--){
				cin >> j;
				s[j].sub[i]=1;
				cin >>s[j].zuo[i];
			}
		}
		cin >> x >> y;
		t+=s[x].kou+s[y].kou;
		for(int i=1;i<=n;i++){
			if(s[x].sub[i]==s[y].sub[i]==1){
				plan[jsq]=t+s[x].zuo[i]+s[y].zuo[i];
				jsq++;
			}
		}
	}
	
	return 0;
}
