#include<bits/stdc++.h>
int n,m,a[500005],sum[300005],pos;
std::vector<int> con(300005),cad(300005);
int main(){
	freopen("r","card.in",stdin);
	freopen("w","card.out",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++) std::cin>>a[i];
	for(int i=1;i<=n;i++){
		pos=1;
		cad.clear();
		con.clear();
		for(int j=i;j<=n;j++){
			if(con[a[j]]){
				for(int k=1;k<=m;k++) std::cout<<cad[k]<<" ";
				for(int k=1;k<=m;k++) std::cout<<con[k]<<" ";
				std::cout<<pos<<std::endl;
				while(cad[pos]!=a[j]){
					pos--;
					con[cad[pos]]--;
				}
				con[a[j]]--;
				for(int k=1;k<=m;k++) std::cout<<cad[k]<<" ";
				for(int k=1;k<=m;k++) std::cout<<con[k]<<" ";
				std::cout<<pos<<std::endl;
			}
			cad[pos]=a[j];
			con[a[j]]++;
			pos++;
		}
		for(int j=1;j<pos;j++) sum[cad[j]]++;
	}
	for(int i=1;i<=m;i++) std::cout<<sum[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
