#include<bits/stdc++.h>
using namespace std;
long long n;
long long d[200005];
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld %c",&d[i],&a[i]);
	}
	long long cnt=0;
	long long q_i=1,q_j=1,id_i=1,id_j=n;
	while(id_i<id_j){
		if(a[id_i]!=a[id_j]){
			cnt++;
		}
		q_i++;
		if(q_i>d[id_i]){
			q_i=1;
			id_i++;
		}
		q_j++;
		if(q_j>d[id_j]){
			q_j=1;
			id_j--;
		}
	}
	printf("%lld",cnt);
	return 0;
}
