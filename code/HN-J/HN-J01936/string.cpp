#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n;
long long int sum;
char a[200005];
int num[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i]>>a[i];
	}
	int k=0;
	int l=n-1;
	while(k<=l&&(k<=n-1&&l>=0)){
		if(num[k]>num[l]){
			if(a[k]!=a[l]){
				sum+=num[l];
			}
			num[k]-=num[l];
			num[l]=0;
			l--;
		}
		else if(num[k]<num[l]){
			if(a[k]!=a[l]){
				sum+=num[k];
			}
			num[l]-=num[k];
			num[k]=0;
			k++;
		}
		else{
			if(a[k]!=a[l]){
				sum+=num[k];	
			}
			num[k]==0;
			num[l]==0;
			l--;
			k++;
		}
		if(num[k]==0&&num[l]==0){
			cout<<sum;
			return 0;
		}
	}
	cout<<sum;
	return 0;
}
