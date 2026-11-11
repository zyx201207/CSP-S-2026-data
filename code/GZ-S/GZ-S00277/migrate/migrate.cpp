//GZ-S00277,贵阳市第十七中学,王浩樾 
#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,d,a[100005];

int main(){
	freopen("migrate.in","w",stdin);
	freopen("migrate.out","r",stdout);
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		cin>>n>>d;
		for(int j = 1;j <= n;j++){
			cin>>a[i];
			cout<<n / d;
		}
	}
	return 0;
}
