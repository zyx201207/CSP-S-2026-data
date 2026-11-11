//GZ-J00220	  遵义市南白初级中学   吴濬嘉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n,m,b[N];
bool a[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		if (!a[x])	a[x] = true;
		else{
			for (int j = 1;j <= n;j++){
				a[j] = false;
			}
			a[x] = true;
		}
		b[x]++;
	}
	for (int i = 1;i <= m;i++){
		cout << b[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
}

