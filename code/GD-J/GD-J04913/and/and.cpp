#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,num=0,max=0;
	cin>>n>>m;
	int k[n];
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	for(int i=0;i<n;i++){
		for(int f=0;f<n;f++){
			for(int g=0;g<m;g++){
				if(g==0){
					num=k[i] and k[f];
				}
				else{
					num=num and k[f];
				}
			}
			if(max<num){
				max=num;
			}
		}
	}
	cout<<max;
	return 0;
}
