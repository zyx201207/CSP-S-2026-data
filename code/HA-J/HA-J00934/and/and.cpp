#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a1,a2,a3;
int z[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>cnt;
//		while(cnt!=0){
//			int r=0;
//			cnt/=2;
//			
//		}
//	}
//²¿·Ö¡¢
	for(int i=1;i<=n;i++){
		cin>>z[i];
	} 
	sort(z+1,z+1+n);
	cnt=z[n]&z[n-1]&z[n-2];
	cout<<cnt;
	return 0;
}
