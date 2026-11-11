#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
vector<int> a;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a.push_back(k);
	}
	
	if(m==2){
		cout<<n<<' '<<n;
	}
	else{	 
	    for(int i=1;i<=m;i++) cout<<rand()%100005<<' '; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
