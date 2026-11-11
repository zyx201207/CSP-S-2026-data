#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string pv; 
struct ln{
	long long len;
	char s;
}av[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>av[i].len>>av[i].s;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=av[i].len;j++)pv+=av[i].s;
	}
	for(int i=0;i<pv.size()/2;i++){
		if(pv[i]!=pv[pv.size()-1-i]){
			ans++;
			pv[pv.size()-1-i]=pv[i];
		}
	}
	cout<<ans;
}
