#include<bits/stdc++.h>
using namespace std;

int n,m;

int arr[212345][41];

int tong[41];

bool ans[41];

long long x;

void dbg(){
	for(int i=1;i<=n;i++){
		for(int k=0;k<15;k++){
			cout<<arr[i][k];
		}
		cout<<"\n";
	}
	cout<<"./.";
	for(int k=0;k<15;k++){
		cout<<tong[k]<<" ";
	}
	cout<<"\n\n";
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		int len=0;
		while(x){
			arr[i][len]=x%2;
			if(x%2){
				tong[len]++;
			}
			x/=2;
			len++;
		}
	}
	for(int l=33;l>=0;l--){
		if(tong[l]>=m){
			ans[l]=true;
			memset(tong,0,sizeof tong);
			for(int i=1;i<=n;i++){
				if(arr[i][l]){
					for(int k=0;k<=33;k++){
						tong[k]+=arr[i][k];
					}
				}else{
					for(int k=0;k<=33;k++){
						arr[i][k]=0;
					}
				}
			}
		}
	}
	long long p=1;
	long long rans=0;
	for(int i=0;i<33;i++){
		rans+=p*(int)(ans[i]);
		p*=2;
	}
	cout<<rans;
	return 0;
}
