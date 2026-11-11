#include<bits/stdc++.h> 
using namespace std;
int n,m,ans=0x3f3f3f3f;
long long a[200005];
bool b[2][55];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		int sum=0,x=0;
		for(int j=0;j<n;j++){
			if(sum<a[j]){
				x=j;sum=a[j];
			}
		}
		a[x]=0;
		ans=ans&sum;
	}
	cout<<ans<<endl;
	return 0;
}
