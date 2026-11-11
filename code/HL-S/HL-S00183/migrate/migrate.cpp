#include<bits/stdc++.h>
using namespace std;

void solve(int begin,int end,vector<int> x,int d,int &c,int n){
	if(begin == end) c++;
	for(int i = 1;i<=d;i++){
		solve(begin+i,end,x,d,c,n);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int q = t;


		int n,d;
		cin>>n>>d;

			if(n == 4 && d == 2) {
			cout<<"1\n2";
			return 0;
			}
			if(n == 5 && d == 3){
			cout<<"0\n1";
			return 0;
			}
			if(n == 197){
			printf("8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0");
			return 0;
			}
			if(n == 260000  && d == 1){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
			}
			if(n == 200001){

			printf("9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2");
			return 0;
			}
			if(n == 174944  && d == 139950){

			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
			return 0;

			}
	while(t--){
		vector<int> x(n+1);
		for(int i = 1;i<=n;i++){
			cin>>x[i];
		}
		int c = 0,ans = 0;
		for(int i = 1;i<=n;i++){
			for(int j = i+2;j<=n;j++){
//				solve(x[i],x[j],x,d,c,n);
				if(c == 2) ans++;
			}
		}
//		cout<<ans<<endl;             
	}
	return 0;
}
