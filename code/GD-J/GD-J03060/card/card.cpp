#include <bits/stdc++.h>
using namespace std;
int a[1000005],n,m,a1[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int n1=0,cnt=0,ans=0;
	for(int i=0;i<n;i++){//输入 
		cin>>a[i];
	}
	while(n1<n){
		int n2=n;
		for(int i=n1;i<n;i++){//一局 依次打牌 
			bool f=0;
			for(int j=0;j<n2;j++){
				if(f==1){
					a[j]==0;
					n2--;
				}
				if(a[j]==i){
					f=1;
				}
				else{
					a[n2]=i;
				}
			}
		}
		if(n2!=1){
			for(int i=0;i<n2;i++){
				int n3=a[i];
				a1[n3]++;
				ans++;
			}
		}
		n1++;	
	}
	for(int i=0;i<ans;i++){
		if(a1[i]!=0){
			cout<<a1[i]<<" ";
		}
	}
	return 0;
}
