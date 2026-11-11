#include<bits/stdc++.h>
using namespace std;
int q[500005],w[300005]={0,0,0,0,0},e[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,k,r=0;
	cin>>n>>m;
	vector<int> a;
	for(i=0;i<n;i++){
		cin>>q[i];
		if(n<=m){
			w[i]=0;
		}
	}
	if(n<=500){
		for(i=0;i<n;i++){
			for(j=0;j<r;j++){
				e[j]=0;
			}
			r=0;
			for(j=i;j<n;j++){
				if(r!=0){
					for(k=0;k<r;k++){
						
						if(e[k]==q[j]){
							for(int u=k;u<r;u++){
								e[u]=0;
								r--;
							}
						}
					}
				}
				e[r]=q[j];
				
				r++;
				/*for(k=0;k<a.size();k++){
					if(a[i]==q[j]&&r!=0){
						for(int u=k;u<a.size();u++){
							a.erase(a.begin()+u);
							r--;
						}
						break;
					}
				}
				
				a[r]=q[j];
				r++;*/
			}
			sort(e,e+r);
			for(j=0;j<r;j++){
				
				if(j!=0){
					if(e[j]==e[j-1]||e[j]==0){
						while(e[j]==e[j-1]) j++;
						
					}
				}
				if(e[j]==0){
					while(e[j]==0) j++;
					
				}
				
				
				w[e[j]-1]++;
			}
			//cout<<endl;
		}
		
		for(i=0;i<m;i++){
			cout<<w[i]<<" ";
		}
	}else{
		for(i=0;i<n;i++){
			r=q[i];
			for(j=i;j<n;j++){
				if(j!=i){
					if(q[j]==q[j-1]){
						r=q[i];
					}
				}
			}
			for(j=r;j<=m;j++){
				w[r]++;
			}
		}
		for(i=0;i<m;i++){
			cout<<w[i]<<" ";
		}
	}
	
	return 0;
} 
