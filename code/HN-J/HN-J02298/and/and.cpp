#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max,s,sm=0;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	max=a[1] and a[2];
	while(sm!=m){
		int k=1;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				if(s<(a[i] and a[j])){
					s=a[i] and a[j];
				}
			}	
		}
		s=s and a[k];
		k++;
		sm++;
	}
	max=s;
	cout<<max;
	return 0;
}
