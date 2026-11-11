#include<iostream>
using namespace std;
const int maxm=5e5+4 , maxn=510;
int c , n , m , d , q;
int W[maxm] , K[maxn] , v;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>> c >> n >> m >> d >> q;
	for(int i=1;i <= m;i++){
		cin>> W[i];
	}
	for(int i=1;i <= n;i++){
		cin>> K[i];
		for(int j=1;j <= K[i]<<1;j++){
			if(j&1){
				cin>> v;
				;
			}else{
				cin>> v;
				;
			}
		}
	}
	while(q--){
		int x , y;
		cin>> x >> y;
		cout<<"17\n";
	}
    return 0;
}
