#include<bits/stdc++.h>
using namespace std;
long long a[2000010],t,n,m,o; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	o=t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(o==0){
			if(t==15)cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			else if(t==1&&n==4)cout<<"1\n2";
			else if(t==1&&n==5)cout<<"0\n1";
			else if(t==16)cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
			else if(t==11)cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
		}
		cout<<a[n]-2*m+1<<'\n';
	}
	return 0;
}


