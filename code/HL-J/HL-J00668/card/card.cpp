#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int a[100000],m,n,top=0,sum[100000]={0};
    int last[10000]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			top++;
			last[top]=a[j];
			for(int k=i;k<=top;i++){
				if(last[k]==last[top]&&k!=top){
					for(int del=k;del<=top-1;del++){
						a[del]=0;
					}
					swap(a[k+1],a[top+1]);
					break;
				}
			}
		}
		for(int t=1;t<=top;i++){
			cout<<a[t]<<' ';
		}
	}
}
