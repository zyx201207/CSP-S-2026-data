#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		long long a[n+5],ans[n+5];
		for(int i=0;i<n;i++){
			cin>>a[i];
			ans[i]=0;
		}
		ans[0]=1;
		for(int i=0;i<n;i++){
			for(int j=i+i;j<n;j++){
				if(abs(a[j]-a[i])<=d){
					ans[j]+=ans[i];
				}else{
					break;
				}
			}
		}
		long long an=0;
		for(int i=0;i<n;i++){
			if(ans[i]==2){
				an++;
			}
		}
		cout<<an<<endl;
	}
	return 0;
}