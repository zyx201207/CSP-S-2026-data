#include<bits/stdc++.h>
using namespace std;

vector<int>a;

bool cmp(int a,int b){
	return a>b;
} 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	
	cin>>n>>m;
	a.resize(n+1);
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	sort(a.begin()+1,a.end(),cmp);
		
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans<<endl;
	
	return 0;
}
