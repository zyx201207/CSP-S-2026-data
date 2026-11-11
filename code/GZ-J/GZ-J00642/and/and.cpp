//贵阳市第二十九中学刘一锐GZ-J00642
#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return b<a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,c[200000],ans=0;
	cin>>a>>b;
	for(int i=0;i<a;i++)cin>>c[i];
	sort(c,c+a,cmp);
	ans=c[0];
	for(int i=1;i<b;i++){
		ans=(ans & c[i]);
	}
	cout<<ans;
	return 0;
}
