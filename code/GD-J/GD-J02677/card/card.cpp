#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;
const int M=3e5+5;
int a[N],cnt[M],f[N];
int n,m;
bool ck=1;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]<a[i-1]) ck=0;
	}
	
	if(ck){
		int ss=n;
		for(n=1; n<=ss; n++){
			vector<int> b(n,0);
			int k=0;
			for(int i=n; i<=ss; i++){
				int pos=-1;
				for(int j=k; j>=1; j--){
					if(b[j]==a[i]) pos=j;
					else break;
				}
				
				if(pos!=-1) k=pos;
				else b[++k]=a[i];
			}
			
			for(int i=1; i<=k; i++){
				cnt[b[i]]++;
			}
		}
		for(int i=1; i<=m; i++) cout<<cnt[i]<<' ';
		return 0;
	}
	
	int ss=n;
	for(n=1; n<=ss; n++){
		vector<int> b(n,0);
		int k=0;
		for(int i=n; i<=ss; i++){
			int pos=-1;
			for(int j=1; j<=k; j++){
				if(b[j]==a[i]){
					pos=j;
					break;
				}
			}
			
			if(pos!=-1) k=pos;
			else b[++k]=a[i];
		}
		
		for(int i=1; i<=k; i++){
			cnt[b[i]]++;
		}
	}
	for(int i=1; i<=m; i++) cout<<cnt[i]<<' ';
	return 0;
}
/*4 3
1 2 1 3*/

