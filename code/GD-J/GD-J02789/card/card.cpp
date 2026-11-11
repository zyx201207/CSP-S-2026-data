#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005] = {0};
int shu[300005] = {0};
int b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		b[0] = a[i];
		b[a[i]] = 0; 
		for(int j = i;j <= n;j++){
			b[a[j]] = a[j+1];
		}
		for(int j = 0;;){
			int l = b[j];
			b[j] = 0;
			j = l;
			shu[j]++;
			if(b[j] == 0){
				break;
			}
		}
	}
	for(int i = 1;i <= m ;i++){
		printf("%d ",shu[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
