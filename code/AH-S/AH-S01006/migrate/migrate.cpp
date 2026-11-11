#include<iostream>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,x1,x2,x3;
		cin>>n>>d;
		cin>>x1>>x2;
		for(int i=3;i<=n;i++) cin>>x3;
		long long x=x2-x1;
		if(x*2<=d) cout<<n-3<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}
//The 2026 CSP-J's first problem has a biggggg hole:
//    The seats are 'A','B','C','D' and 'F'!
//I imcorrectly thought they are 'A','B','C','D' and 'E'!
//But now I find that I have seen this fact in the real life.
//I can't change it.
//Too late.My time is gone~   -queue
//wo neng shang mi huo xing wei da shang ma
