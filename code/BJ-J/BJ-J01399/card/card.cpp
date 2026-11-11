#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin >> n >> m;
	int a[n],b[m],zhan[n];//a->数字 b->输出
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int k=0,top=0;
	for(k=0;k<n;k++){
		for(int i=k;i<n;i++){
			for(int l=0;l<n;l++){
				if(zhan[l]==zhan[top]){
					top=l;
				}
			}
			zhan[top]=a[i];
			top++;
		}
		for(int i=0;i<n;i++){
			int u=zhan[i];
			b[u]++;
		}
	}
	for(int i=0;i<n;i++){
		cout << b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}