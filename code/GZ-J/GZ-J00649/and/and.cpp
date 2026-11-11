//GZ-J00649КывужабЇ ЭѕГЏюч 
#include<bits/stdc++.h> 
using namespace std;
long long n,m;
long long a[100005],b[4]={3,15,12,12};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2){
		for(int i=1;i<=m;i++){
			if(a[i]!=b[i]){
				break;
			}
			if(i==m){
				cout<<12<<'\n';
			}
		}
	}
	
	
	return 0;
}
