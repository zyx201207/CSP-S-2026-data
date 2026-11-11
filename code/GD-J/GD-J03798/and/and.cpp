#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int n,m,a[1005],max=-100;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<n;j++){
		for(int k=j;k<n;k++){
			if(a[j] and a[k]>max){
				max=a[j] and a[k];
			}	
		}
	}
	cout<<max;
	return 0; 
}
