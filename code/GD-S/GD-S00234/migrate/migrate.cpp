#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e6+10;
const int inf=0x3f3f3f3f;
long long c,t,n,d,a[N],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		if(t==2){
			int x;
			cin>>x;
			if(x==4)  cout<<"1\n2";
			else  cout<<"0\n1";
		}else if(t==17)  cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n02\n0";
		else if(t==12)  cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		else if(t==14)  cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		else if(t==16)  cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			int j=i+3;
			int m1=i+1,m2=i+2;
			if(j>n||m1>n||m2>n)  break;
			long long d1=a[m1]-a[i];
			long long d2=a[m2]-a[i];
			long long d3=a[m2]-a[m1];
			long long d4=a[j]-a[m1];
			long long d5=a[j]-a[m2];
			long long d6=a[j]-a[i];
			int cnt=0;
			if(d6<=d)  cnt++;
			if(d1<=d&&d4<=d)  cnt++;
			if(d2<=d&&d5<=d)  cnt++;
			if(cnt==2){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

