#include<iostream>
using namespace std;
int a[500005],b[500005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",strout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int k = 1;
		for(int j = i;j <= n;j++,k++){
			int q;
			bool f = 1;
			for(q = 1;q <= n;q++){
				if(b[q] == a[j]){
					for(int p = q;p <= n;p++){
						b[p] = 0;
					}
					f = 0;
					break;
				}
			}
			if(f)k = q;
			b[k] = a[j];
			k++;
		}
		for(int j = i;j <= n;j++){
			c[b[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << c[i] << " ";
	}
	return 0;
}
