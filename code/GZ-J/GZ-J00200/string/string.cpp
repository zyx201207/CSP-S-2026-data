//GZ-J00200 观山湖中学 马志翔  
#include<bits/stdc++.h>
using namespace std;
void ji(){
	long long n;
	cin>>n;
	vector< pair<long long,string> >a(n+1);
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		sum+=a[i].first;
	}
	vector<string>b(sum+1);
	long long x=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].first;j++){
			x++;
			b[x]=a[i].second;
		}
	}
	long long ans=0;
	for(int i=sum;i>=1;i--){
		if(b[i]!=b[sum-i+1])ans++;
	}
	cout<<ans/2<<endl;
	return;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int t=1;
    //cin>>t;
	while(t--){
		ji();
	} 
	return 0;
}
