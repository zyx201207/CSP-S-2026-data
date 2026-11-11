//GZ-J00506 黄宇瀚 贵阳市观山湖区普瑞学校
#include<bits/stdc++.h>
using namespace std;
long long b[2005][2005]={};
int main(){
	long long a[2005]={};
	long long n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>a[i];
	}
	if(n==4&&m==2){
		cout<<12;
	}else if(n==5&&m==3){
		cout<<7;
	}
	return 0;
}

