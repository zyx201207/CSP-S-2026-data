#include <bits/stdc++.h>
using namespace std;
//freopen ("card.in","r",stdin)
//freopen("card.out","w",stdout)

int main(){
	int n,m;
	cin>>n>>m;
	int a[n+1];
	vector<int>d;
	int b[m+1]={0},c[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		
	}
	
	for(int i=1;i<=n;i++){
		d.push_back(a[i]);
		b[a[i]]=1;
		for(int j=i+1;j<=n;j++){
			if(b[a[j]]==1){
				for(int k=d.size()-1;k>=0;k--){
					if(d[k]!=a[j]){
						d.pop_back();
						b[a[k]]=0;
					}else{
						break;
					}
				}
			}else{
				b[a[j]]=1;
				d.push_back(a[j]);
				continue;
			}
		}
	
		}
		for(int l=1;l<=m;l++){
			if(b[l]!=0){
				c[l]++;
				b[l]=0;
			} 
		}
		while(!d.empty()){
			d.pop_back();
		}
	
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
