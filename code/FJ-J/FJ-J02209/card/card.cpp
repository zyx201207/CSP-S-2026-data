#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if(n<=500){
		int a[5005],b[5005],c[5005];
		memset(c,0,sizeof(c));
		int t = 1;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				bool f=1;
				int u;
				for(int k=1;k<=j&&f;k++){
					if(b[k]==a[j]){
						f = 0;
						u = k+1;
					}	
				}
				if(!f){
					for(int k=u;k<t;k++)
						b[k] = 0;
					t = u;
				}
				else{
					b[t++] = a[j];
				}
			}
			for(int j=1;j<t;j++){
				cout << b[j];
				c[b[j]] ++;
			}
		}
		for(int i=1;i<m;i++)
			cout << c[i] << " ";
		cout << m;
		cout << "\n";
		return 0;
	}
	return 0;
}
