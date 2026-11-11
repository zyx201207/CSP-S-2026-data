//#include<bits/stdc++.h>
//using namespace std;
//long long a,b[1000001],m,qw;
//int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
//	cin>>a>>m;
//	for(int i=1;i<=a;i++) cin>>b[i];
//	sort(b+1,b+a+1);
//	qw=b[a];
//	cout<<b[a];
//	for(int i=a-1;i>=a-m+1;i--){
//		qw&=b[i];
//	}
//	cout<<qw;
//	return 0;
//	
//}
#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],sheng[1000001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int qwq[100001]={0},ka=1,jei=1,cpp=0;
		for(int j=i;j<=n;j++){
			int yo=0;
			for(int u=ka;u<=jei;u++){
				if(cpp){
					qwq[u]=0;
					continue;
				}				
				if(qwq[u]==a[j]){
					cpp=1;
					yo=u;
				}
			}
			if(yo)jei==yo;
			else jei++;
		}
		for(int kl=ka;kl<=jei;kl++){
			sheng[qwq[kl]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sheng[i]<<" ";
	}
	return 0;
	
}
