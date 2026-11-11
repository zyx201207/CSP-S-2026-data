#include<bits/stdc++.h>
using namespace std;
int main(){
	int num=0;
	int n,m;
	cin>>n>>m;
	int rum=0;
	int a[107];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=m;j++){
			if(a[i]=a[i+1]){
				num+=2;
				m++;
//				rum+=a[i]+a[i+1];
//				if()
				a[i++];	
			}else{
				a[i]++;
				num++;
				break;
			}
		}
	}
	cout<<num;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	
	return 0;
}
