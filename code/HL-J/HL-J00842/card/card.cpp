#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a;
	long long b;
	cin >> a >> b;
	long long c[b];
	for(int i=0;i<b;i++){
		c[i]=0;
	}
	long long arr[a];
	for(int i=0;i<a;i++){
		cin >> arr[i];
	}
	for(int i=0;i<a;i++){
		long long num[a];
		for(int j=i;j<a;j++){
			num[j]=arr[j];
		}
		for(int j=i;j<a;j++){
			for(int k=j;k<a;k++){
				if(num[j]==num[k]&&j!=k){
					for(int l=j;l<k;l++){
						num[l]=0;
					}
				}
			}
		}
		for(int j=1;j<b;j++){
			for(int k=i;k<a;k++){
				if(num[k]==j){
					c[j-1]++;
				}
			}
		}
	}
	for(int i=0;i<a;i++){
		cout << c[i]<<" ";
	}
	
	return 0;
}