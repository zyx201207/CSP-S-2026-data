//GZ-J00167 贵阳市第一中学 谢云龙 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool oii[N][35];
bool ioa[N];
//log2(N)=17.~
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=30;j>=0;j--){
			if(x>=(1<<j)){
				oii[i][j]=1;
				x-=(1<<j);
			}
//			cout<<oii[i][j];
		}
//		cout<<"\n";
		ioa[i]=1;
	}
	int ans=0;
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(ioa[i]&&oii[i][j])cnt++;
//			cout<<ioa[i];
		}
//		cout<<"<-"<<j<<"  cnt="<<cnt<<"\n";
		if(cnt>=m){
			ans+=(1<<j);
			for(int i=1;i<=n;i++){
				ioa[i]&=oii[i][j];
			}
		}
	}
	cout<<ans;
	return 0;
}
