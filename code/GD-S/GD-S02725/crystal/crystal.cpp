#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005];//定义
int main()
{
	int sum=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout) ;
	cin>>n>>m;
	for(int i=0;i<n;i++){//输入
		cin>>a[i];
	}
	for(int i=0;i<n;i++){//计算
		while(a[i]<a[i+1]){
			if(a[i]<a[i+1]){
				a[i]+=1;
				sum++;
			}
				if(sum==m){
				break;
			}
		}
	}
	cout<<sum/2;//输出
	return 0;
}
