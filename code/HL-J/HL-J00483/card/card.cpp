#include <bits/stdc++.h>
using namespace std;
int a[50005], b[30005], cnt[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cntn=1;
	for(int j=1;j<=n;j++){
		int p=0;
		for(int i=cntn;i<=n;i++){
			int x;
			x=a[i];
			if(b[x]==0){
				b[x]++;			
			}else{
				p=i;
				b[x]=1;
			}
		}
		for(int c=p;c<=n;c++){
			int y=a[c];
			cnt[y]++;
		}
		cntn++;
		for(int l=0;l<=m;l++){
			b[l]=0;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout << cnt[i] << ' ';
	}
	
	return 0;
}
