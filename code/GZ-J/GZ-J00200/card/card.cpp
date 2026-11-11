//GZ-J00200 观山湖中学 马志翔  
#include<bits/stdc++.h>
using namespace std;
void ji(){
	long long n,m;
	cin>>n>>m;
	vector<long long>a;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
	}
	vector<long long>ans(m+1);
	for(int i=1;i<=n;i++){
		a.push_back(a.front);
		a.pop();
		if(a[i]==i)ans[i]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}cout<<endl;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int t=1;
    //cin>>t;
	while(t--){
		ji();
	} 
	return 0;
}
