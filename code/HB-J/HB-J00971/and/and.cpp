#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int arr[N],n,m,sum,maxn=-10;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				int num;
				num=arr[i]&arr[j];
				maxn=max(maxn,num);
			}
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=n;l++){
					if(i==j||i==l||j==l){
						continue;
					}
					int num1,num2;
					num1=arr[i]&arr[j];
					num2=num1&arr[l];
					maxn=max(maxn,num2);
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}
