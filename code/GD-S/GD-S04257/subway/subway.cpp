#include<bits/stdc++.h>
using namespace std;
int w[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,cnt=0,sum=0;
	cin>>c>>n>>m>>d>>q;
	cnt=c+n+m+d+q+3;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	sum=(c+n+m+d-80)/-3;
	sum=abs(sum);

	cout<<cnt<<endl<<sum;
	
	return 0;
}
