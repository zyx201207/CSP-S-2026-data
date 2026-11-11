//姓名：赵梦砚西 准考证号：GZ-J00336 学校：贵阳市第十八中学
#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,k;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
} 
