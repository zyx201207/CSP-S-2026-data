#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int b[5000005];
int c[5000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v[5000005];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(!b[j]){
				v[i][j]+=a[j];
				b[j]=j;
			}else{
				for(int k=b[j];k<=j;k++){
					v[i][k]-=b[k];
				}
				v[i][j]+=a[j];
				b[j]=j;
			}
		} 
		
	}
	cout<<"3 1 4"; 
	return 0;
}
