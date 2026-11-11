#include<bits/stdc++.h>
using namespace std;
//存储结果
long long ans=0; 
long long a[500005];
//排序，小在前，大在后，每次都把之前水晶能量加到和下一个平齐 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n;
	long long m;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//从小到大排序 
	a[0]=INT_MIN;
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	//增加水晶能量
	for(int i=1;i<=n;i++){
		//判断是否需要增加能量 
		if(a[i]<=a[i+1]){
			//判断是否能量还够
			if(m>=i*(a[i+1]-a[i])){
				//把之前的水晶都加到和下一个平齐 
				m-=i*(a[i+1]-a[i]);
				//结果加1
				ans+=1;
			}
			else{
				cout<<ans+1;
				return 0;
			}
		}
	}
	cout<<ans+1;
	return 0;
} 
