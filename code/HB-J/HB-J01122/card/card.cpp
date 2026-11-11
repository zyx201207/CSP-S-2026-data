#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N];
int v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int now1=0;
		for(int j=i;j<=n;j++){
			int flag=0;
			for(int k=1;;k++){
				if(v[k]==0)break;
				if(v[k]==a[j]){
					flag=1;
					for(int l=k;;l++){
						if(v[l]==0){
							break;
						}else{
							v[l]=0;
						}
					}
				}		
			}
			if(flag==0){
				v[now1]=a[j];
				now1++;
			}
		}
		for(int i=0;i<now1;i++){
			b[v[i]]++;
		}
	}
	for(int i=m;i>=1;i--){
		cout<<b[i]<<" ";
	}
	return 0;
}
