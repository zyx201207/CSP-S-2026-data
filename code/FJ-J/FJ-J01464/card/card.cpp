#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t[300010],p=1;
		for(int j=i;j<=n;j++){
			bool flag=1;
			for(int k=p-1;k>=1;k--){
				if(t[k]==a[j]){
					p=k;
					flag=0;
				}
			}
			if(flag){
				p++;
				t[p]=a[j];
			}
//			for(int k=1;k<=p;k++){
//				cout<<t[k]<<' ';
//			}
//			cout<<endl;
		}
		for(int j=1;j<=p;j++){
			b[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
//我是lz
//10:30
//预期12-48 
//二等预订，总得222-258 
//闹肚子8:30-12:00...... 
//空调好冷
//好安静
//我有1.4了
//t3,t4什么怪物 
