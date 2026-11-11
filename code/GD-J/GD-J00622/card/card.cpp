#include<iostream>
#include<vector>
using namespace std;
int a[1000000],ans[1000000];
vector<int> pai;
int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	//cout<<"test";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int ca=a[j];
			for(int k=0;k<pai.size();k++){
				if(pai[k]==ca){
					for(int l=k;l<pai.size();l++){
						a[l]=0;
					}
				}
			} 
			pai.push_back(ca);
		}
	//	cout<<"test";
	
	
		for(int j=0;j<pai.size();j++){
			if(pai[j]>0) ans[pai[j]]++;
		}
//		 for(int j=0;j<pai.size();j++){
//		 	cout<<pai[j]<<' ';
//		 }
		
		//cout<<"test";
		for(int j=0;j<pai.size();j++){
			pai[j]=0;
		}
	//	cout<<endl;
	} 
	//cout<<"test";
	//for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	for(int i=1;i<=m;i++){
		if(i<=m&&ans[i]>0){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
