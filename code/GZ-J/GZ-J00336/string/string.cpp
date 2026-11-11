//姓名：赵梦砚西 准考证号：GZ-J00336 学校：贵阳市第十八中学
#include<bits/stdc++.h>
using namespace std;
long long cnt,a[1000005],c[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string s;
	string hw;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i]*c[i];
	}
	for(long long i=1;i<=n;i++){
		if(s==hw){
			cout<<"0";
			return 0;
		}
		else{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
