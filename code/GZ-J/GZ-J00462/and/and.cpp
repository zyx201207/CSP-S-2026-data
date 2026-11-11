//GZ-J00462 遵义市第十一中学 祝家懿 
#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	int mx=-2e9;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(i==j){
				continue;
			}
			int p=(a[i]&a[j]);
			if(p>mx){
				mx=p;
			}	
		}
	}
	cout<<mx;
	return 0;
} 
