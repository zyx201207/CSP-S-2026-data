#include<bits/stdc++.h>
using namespace std;
long long pai[100001];
long long lei[1001];
long long xian[100001],q=0;//q定位 jiang将要打出 
void pdxt(int n){
	for(int i=0;i<q;i++){
		if(xian[i]==n){
			for(int j=n;j<=q;j++){
				xian[j]=0;
			}
			q=n-1;
		}else{
			xian[q+1]=n;
			q++;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//ios::sync_with_stdio(false);
//	cin.tie(0);
	//cout.tie(0);
long long m,n,t=0;//t总 
cin>>m>>n;
for(int i=0;i<n;i++){
	cin>>pai[i];
}
 for(int i=0;i<n;i++){
 	for(int j=i;j<n;j++){
 			pdxt(pai[j]);
	 }
	 for(int j=i;j<q;j++){
	 	lei[xian[j]]++;
	 }
	 q=0;
 }
	for(int i=0;i<m;i++){
		cout<<lei[i]<<" ";
	}
	return 0;
}

