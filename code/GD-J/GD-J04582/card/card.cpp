#include <bits/stdc++.h>
using namespace std;
long long n,m,ar[500010],br[300010],cr[900010],t[300010],s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for(int i=1;i<=n;i++){
		s=1;
		for(int j=i;j<=n;j++){
			if(t[ar[j]]>=1){
				for(int k=n;k>=1;k--){
					if(br[k]==ar[j]){
						break;
					}
					if(t[br[k]]!=0){
						t[br[k]]--;
					}
					br[k]=ar[j];
					s--;
				}
			}else{
				t[ar[j]]++;
				br[s]=ar[j];
				s++;
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]>=1){
				cr[j]++;
			}
			t[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cr[i]<<' ';
	}
	
	return 0;
}
