#include<bits/stdc++.h>
using namespace std;
const int T=1e5+5;
int a[T],s[T],zhi[T];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int pai=i;
		while(pai!=n){
			
			for(int j=pai;j<n;j++){
				if(s[j]==a[pai]){
					for(int l=j;l<n;l++){
						s[l]=0;
					}
					break;
				}
			}
			s[pai]=a[pai];
			pai++;
		}
		for(int k=0;k<=m;k++){
			
			zhi[s[k]]+=1;
			s[k]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<zhi[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
