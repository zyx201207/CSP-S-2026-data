#include<bits/stdc++.h>
using namespace std;
long long n,m,new_m;
int a[500005],b[500005];
int cnt,new_cnt;
bool cmp(int x,int y){
	return x<=y;
}
int main(){
	//输入
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	new_m=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	//遍历每一个
	int p=0;
	for(int i=1;i<=n;i++){//从第1个开始遍历 
		p=a[i];
		for(int j=1;j<=n;j++){
			if(a[j]<=p && a[j]>=0){
				b[j]=p-a[j];
			}
			sort(b+1,b+n+1,cmp);
			for(int k=1;k<=n;k++){
				if(new_m>=b[k] && p-b[j]!=0 && p-b[j]<=new_m){
					b[j]=b[j]+(p-b[j]);
					new_m=new_m-(p-b[j]);
					cnt++;
				}
			}
		}
		new_cnt=max(new_cnt,cnt);
		cnt=0;
		new_m=m;
	}
	//输出 
	cout<<new_cnt;
	return 0;
}
