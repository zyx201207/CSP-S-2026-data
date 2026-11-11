//GZ-J00481 遵义市第十九中学 刁奕杰 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200004][34];
	int m,n;
	int num=0;
	cin>>n>>m;
	int b;
	int j=1;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=30;i++){
			a[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b;
		while(b>0){
			a[i][j]=b%2;
			b/=2;
			j++;
		}
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	bool st=1;
	int d=1;
	if(m==n){
		for(int i=1;i<=30;i++){
			for(int j=1;j<=n;j++){
				if(a[j][i]==0){
					st=0;
					break;
				}
			}
			if(st==1){
				for(int j=1;j<=i;j++){
					d*=2;
				}
				num+=d;
			}
		}
		cout<<num;
	}
	return 0;
}

