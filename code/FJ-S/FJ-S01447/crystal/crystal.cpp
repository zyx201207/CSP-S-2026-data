#include<bits/stdc++.h>
using namespace std;
int a[10005],n,m,k,num;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m>0){
		for(int j=1;j<=n;j++){
			k=0;
			sort(a+j,a+n+1);
			a[j]++;
			for(int i=1;i<=n;i++){
				if(a[j]==a[j+1]){
					k++;
				}
				cout<<a[j]<<" ";
			}
			cout<<endl;
			if(k!=0) k++;
			num=max(num,k);
			if(num==k){
				m--;
			}
		}
	}
	cout<<num/2;
	return 0;
} 
