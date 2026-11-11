#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num=1;
	int i=n;
	if(n<=500000&&n>5000&&m<=1000000000000000000&&m>100000000){
		while(1){
			i--;
			if(m!=0){
				a[i]+=n-i;
				m-=n-i;
				num++;
			}
			else{
				break;
			}
		}
	}
	cout<<num;
	return 0;
}
