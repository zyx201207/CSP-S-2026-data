#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int b[N];
int main(){
	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		string str;
		bool flag = false;
		int minn = N;
		int oi = i;
		for(int j = i;j <= n;j++){
			for(int k= oi+1;k <= n;k++){
				if(k == j)continue;
				if(a[j] == a[k] && !flag){
					oi = k;
				}
			}
		}
		
		for(int j = oi;j <= n;j++){
			b[a[j]]++;
			
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<b[i]<<" ";
	}
}


