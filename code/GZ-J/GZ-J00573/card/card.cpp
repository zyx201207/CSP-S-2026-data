//GZ-J00573  遵义市第四初级中学  何雨泽 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int x[100001]={};
	int brr[100001]={};
	string arr="";
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(x[(arr[j]-'0')]>0){
				for(int k=1;k<j;k++){
					if(x[k]>=(arr[j]-'0')){
						x[k]=0;
					}
				}
				x[(arr[j]-'0')]=j;
			}
			else{
				x[(arr[j]-'0')]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(x[j]!=0){
				brr[j]++;
			}
			x[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<brr[i]<<' ';
	}
	return 0;
}

