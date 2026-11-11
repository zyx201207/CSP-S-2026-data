#include<bits/stdc++.h>
using namespace std;
set<long long>a;
long long s[100005],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int o=i;o<=n;o++){
			if(a.find(s[o])>=a.end())a.push(s[o]);
			
		}
		
	}
	return 0;
}
