#include<iostream>
#include<vector>
#include<map>
int arr[200001],mark[200001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
	int n,m;std::cin>>n>>m>>arr[1];
	bool markA=true;
	for(int i=2;i<=n;i++){
		std::cin>>arr[i];
		if(arr[i-1]>arr[i]){
			markA=false;
		}
	}
	if(markA){
		for(int i=1;i<=n;i++){
			mark[arr[i]]+=i;
		}
	}else{
		for(int i=1;i<=n;i++){
			std::vector<int>tab(n-i+2,0);
			std::map<int,int>set;
			int k=0;
			for(int j=i;j<=n;j++){
				if(set[arr[j]]==0||set[arr[j]]>=k+1){
					tab[++k]=arr[j];
					set[arr[j]]=k;
				}else{
					k=set[arr[j]];
				}
			}for(int j=1;j<=k;j++){
				mark[tab[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		std::cout<<mark[i]<<" ";
	}
return 0;}
