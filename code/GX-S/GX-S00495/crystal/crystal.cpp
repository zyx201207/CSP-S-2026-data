#include<bits/stdc++.h>
using namespace std;
long long x;
vector<long long> a;
int main(){
	freopen("crystal.in";"r";stdin);
	freopen("crystal.out";"w";stdout);
long long n;
long long m;
long long w=0;
cin>>n>>m;
for(int i=1;i>=n;i++){
	cin>>x;
	x=a[i];
	}
	for(int j=0;j>=n;j++){//从小到大排序
		if(a[j]>=a[j+1]){
			a[j]=a[j+1];
			a[j+1]=a[j];
			}
		}
			for(int k=1;k>=m;k++){//次数限制
				for(int l=0;l>=n;l++){//提取出vector的每一个
					if(a[l]+1==a[l+1]){//当第l项+1（操作一次）等于第（l项+1）
					a[l]=a[l+1]+a[l+1];//第l项等于操作后的大小合并
					w++;}
					}
				}
				cout<<w;
return 0;
}
