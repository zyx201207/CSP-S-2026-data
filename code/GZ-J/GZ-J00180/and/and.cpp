//CZ-J00180  遵义市汇川区第一小学 张馨艺
#include<bits/stdc++.h>
using namespace std;
int a[19999];
int ma=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		sum=a[i+1]&&a[i];
		if(sum>=ma){
			ma=sum;
		}
	}
	cout<<ma;
	return 0;
}
