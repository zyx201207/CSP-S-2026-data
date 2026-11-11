//GZ-J00215    贵州省瓮安第二中学    卢浩宇
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int xxs[200005],a,b,ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>xxs[i];
		if(xxs[i]>ma) ma=xxs[i];
	}
	cout<<ma;
	return 0;
}
