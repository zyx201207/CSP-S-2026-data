#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	int m,n,o=0,check = 0;
	cin >> n >> m;
	int a[5005];
	int final[5005];
	int play[5005];
	for(int i = 0;i <= n-1;i++){
		cin >> a[i];
	}
	for(int q = 1;q <= n;q++){
		for(int k = 0;k <= n-q;k++){
			for(int j = 0;j <= o;j++){
				if(play[j] == a[j]) check++;
			}
			if(check == 1){
				for(int i=0;i <= o;i++){
					play[i] = 0;
				}
			}
			play[q] = a[q];
			o++;
		}
		for(int t = 0;t <= o-1;t++){
			if(t == (o+1)) final[t]++;
		}
	}
	for(int z = 0;z <= n-1;z++){
		cout << final[z] << " ";
	}
	
}
