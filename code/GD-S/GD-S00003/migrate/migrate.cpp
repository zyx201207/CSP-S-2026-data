#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int c,t;
int n,d;
int ans = 0,num = 0;
int sum = 0;
int u,v;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(a[i] - a[j] <= d){
				num++;
			}
			int m = u - v;
			sum = m - 1;
			//sort(num + 1,num + 1 + n);
		}
	}
	cout<<num<<endl;
	return 0;
}
