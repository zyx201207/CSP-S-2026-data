#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[20005];
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	sort(a,a+m,cmp);
	int c;
	for(int i=0;i<n-m;i++){
		cin>>c;
		for(int j=0;j<m;j++){
			if(a[j]<c){
				a[j]=c;
				break;
			}
			
		}
	}
	
	int ans=a[0];
	for(int i=1;i<m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
