#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n,m,a[N],b[N],x,ans,ma;
//set<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++) {
		scanf("%d",&a[i]);
	}
	
	if(m == 1){
		printf("%d",n);
		return 0;
	}
	/*if(m == 2){
		for(int i = 1; i <= n; i++) {
			s.clear();
			x ++;
			for(int j = x; j <= n; j++){
				if(s.count(a[j])) {
					s.clear();
					s.insert(a[j]);
				}
			}
			if(s[0]) b[1] ++;
			if(s[1]) b[2] ++;
		}
		printf("%d%d",b[1],b[2]);
	}*/
	return 0;
}
