#include <iostream>
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,t;
	std::cin>>m>>n;
	int a[m-1],b[10000];
	for(int i=0;i<n;i++){std::cin>>a[i];}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){	
			for(int k=0;k<m;k++){
				if(a[k]==a[j]){
					if(k>j){
						t=k;
					}else{
						t=j;
					}
				}
			}
		}for(int j=t+1;j<n;j++){
			b[a[j]]++;
		}
	}for(int i=0;i<n;i++){
		std::cout<<b[i];
	}
	return 0;
}

