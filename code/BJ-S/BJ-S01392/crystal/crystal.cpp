#include <bits/stdc++.h>
using namespace std;
int a[100010];
int ret;
int cnt;
int b;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			ret+=a[j];
			b++;
			if((ret+m)/n==a[j])
			{
				for(int k = n;k >= 0;k--){
					for(int l = 0;l < n;l++){
						cnt=m;
					}
				}
				break;
			}
		}
		b=0;
	}
	cout<<m-(m-b);
	return 0;	
}
