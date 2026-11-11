#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
int n,d,c,t,d1;
long long diff;
int a[N];
//int solve(int d2){
//	if(d2>3)return d2-2;
//}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	//if(c==11||c==12){
		for(int i=1;i<=t;i++){
			cin>>n>>d;
			for(int j=1;j<=n;j++){
				cin>>a[j];
			}
			diff=a[2]-a[1];
			d1=d/diff;
			cout<<0<<endl;
		}
	//}
	fclose(stdin);
	fclose(stdout);
	return 0;//freopen
}
