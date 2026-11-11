#include <iostream>
using namespace std;
const int MAXM = 3 * 1e5;
const int MAXN = 5 * 1e5;
int N , m;
int a[MAXN] , ans[MAXM];
int boo[MAXM];
int n[MAXM] = {-1};
void init(){
	for(int i = 0 ; i <= m ; i++) boo[i] = 0;
	for(int i = 1 ; i <= m ; i++) n[i] = -1;
	return;
}
void popp(int t){
//	int temp = n[t];
//	while(temp != -1){
//		boo[temp] = 0;
//		temp = n[temp];
//	}
	if(n[t] != -1) boo[n[t]]=0;
	if(n[n[t]] != -1) boo[n[n[t]]]=0;
	if(n[n[n[t]]] != -1) boo[n[n[n[t]]]]=0;
	n[t] = -1;
	return;
}
void cnt(){
	int temp = n[0];
	while(temp != -1){
		ans[temp]++;
		temp = n[temp];
	}
	return;
}
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> N >> m;
	for(int i = 1 ; i <= N ; i++) scanf("%d" , &a[i]);
	for(int i = 1 ; i <= N ; i++){
		n[0] = a[i]; init(); boo[a[i]] = 1;
		for(int j = i + 1; j <= N ; j++){
			if(boo[a[j]]){
				popp(a[j]);
				continue;
			}
			boo[a[j]] = 1;
			n[a[j-1]] = a[j];
		}
		cnt();
	}
	for(int i = 1 ; i <= m ; i++) printf("%d " , ans[i]);
	return 0;
}
