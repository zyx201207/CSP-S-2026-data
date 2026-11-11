#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+3;j<n;j++){
				int t=0,s=0;
				for(int k=i+1;k<j;k++){
					if(a[k]-a[k-1]>d){
						t=1;
						break;
					}else{
						s++;
					}
					//cout<<s<<" "<<a[k]<<" "<<a[k-1]<<endl;
				}
				if(t!=1&&s==2) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}