#include<iostream>
#include<cstdio>
#include<map>
int n,m,a[500005];
int ans[500005],t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
		//tl[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		int tn=0;
		for(int j=i;j<=n;j++){	
			bool r=0;
			for(int k=1;k<=tn;k++){
				if(t[k]==a[j]){
					tn=k;
					r=1;
					break;
				}
			}
			if(r==0){
				tn++;
				t[tn]=a[j];
			}
		}
		for(int i=1;i<=tn;i++){
			//std::cout<<t[i]<<' ';
			ans[t[i]]++;
		}
		//std::cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		std::cout<<ans[i]<<' ';
	}
	return 0;
}
