#include <bits/stdc++.h>
using namespace std;
//const int N =3e5+101;
int n,m,a[30010],ans[30000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin >> n >> m ;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int l[30000],b[30000];
		memset(b,0,sizeof(b));
		memset(l,0,sizeof(l));		
		for(int j=i;j<=n;j++){
			if(l[a[j]]==0)l[a[j]]=j;
			else{
				b[l[a[j]]]--;
				b[j]++;
				l[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			b[j]=b[j-1]+b[j];
			if(b[j]>=0)ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout << ans[i]<< " " ;
	
//	for(int i=1;i<=n;i++){
//		int b[30005],l[30005];
//		for(int j=i;j<=n;j++){
//			
//		}
//	}
	return 0 ;
}

