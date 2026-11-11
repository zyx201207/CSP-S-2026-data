#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[500005],t1[300005],t[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		memset(t,0,sizeof(t));
		memset(b,0,sizeof(b));
		for(int j = i;j <= n;j++){
			if(t[a[j]] == 0){
				t[a[j]]++;
				b[j] = a[j];
				for(int i = 1;i <= m;i++){
					cout << t[i] << " ";
				}
				cout << endl;
			}
			else{
				int q;
				for(int x = i;x <= j-1;x++){
					if(b[x] == a[j]){
						q = x;
					}
				}
				for(int x = j-1;x >= i;x--){
					if(b[x] == a[j] && x == q){
						t[b[x]] = 1;
						break;
					}
					t[b[x]] = 0;
					b[x] = 0;
				}
				for(int i = 1;i <= m;i++){
					cout << t[i] << " ";
				}
				cout << endl;
			}
		}
		for(int j = 1;j <= m;j++){
			cout << t[i] << " ";
			t1[i] += t[i]; 
		}
		cout << endl;
	}
	for(int i = 1;i <= m;i++){
		cout << t1[i] << " ";
	}
	return 0;
}
