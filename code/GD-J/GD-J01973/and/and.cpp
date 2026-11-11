#include<bits/stdc++.h>
using namespace std;
int two_m(int x){
	if(x==1)return 1;
	return two_m(x/2)+1;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,t=0,ans=0;
	cin>>n>>m;
	m--;
	vector<int> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end(),cmp);
	t=two_m(v[m]);
	int i=m-1;
	ans=v[m];
	while(i>=0&&two_m(v[i])==t){
		ans=ans&v[i];
		i--;
	}
	cout<<endl<<ans<<endl;
	return 0;
} 
//Trick||Treat!
