#include<bits/stdc++.h>
using namespace std;
int c,t,a[310],ans[100010],ind=1;
int main(){
	cin>>c>>t;
	int x_1=t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		int num=0;
		for(int i = 1;i<=n-3;i++){
			for(int j = i+3;j<=n;j++){
				for(int k = i+1;k<=j-1;k++){
					if(a[j]-a[i]>d && a[k]-a[i]<=d && a[j]-a[k]<=d) num++;
				}
				if(num==2){
					ans[ind]+=1;
				}
				num=0;
			}
		}
		ind++;
	}
	for(int i = 1;i<=x_1;i++){
		cout<<ans[i]<<endl; 
	}
	return 0;
}
