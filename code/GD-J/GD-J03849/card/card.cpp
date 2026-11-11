#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m,zg=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int w[n];
	for(int i=0;i<n;i++){
		int zg=i;
	    int zm[n]{};
		for(int j=i;j<n;j++){
			auto cz=find(zm+i,zm+j,a[j]);
			if(cz!=zm+j){
				for(auto l=cz;l<zm+j;l++){
					zm[*l]=0;
					zg--;
				}
			}
			    zm[++zg]=a[j];
		    
		}
		if(find(zm,zm+n,i)!=zm+n)w[i]++;
	}
	for(int i=0;i<n;i++){
		cout<<w[i]<<' ';
	}
    return 0;
}
