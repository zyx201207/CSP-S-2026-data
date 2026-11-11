#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],t = 0,sum = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 2;i <= n;i++){
		t = 0;
		for(int j = i;j > 0;j--){
			b[j] = a[i] - a[j];
			t += b[j];
			if (t == m){
				if(j > sum){
					sum = i - j;
				}
				if(a[i - 1] == a[i]){
					sum++;
				}
				break;
			}
	    }
	}
	if(sum != 0){
		sum++;
	}
	printf("%d",sum);
	return 0;
}
