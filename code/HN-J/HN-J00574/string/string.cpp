#include<bits/stdc++.h>
using namespace std;
struct hw{
	long long cd;
	char x;
}a[100010];
int n;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cd>>a[i].x;
		sum+=a[i].cd;
	}
	for(int i=2;i<=n;i++){
		if(a[1].x!=a[i].x){
			cout<<sum/2;
			return 0;
		}
	}
	cout<<0;
} 
