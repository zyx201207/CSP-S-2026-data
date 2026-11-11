#include <bits/stdc++.h>
using namespace std;
#define int Long Long
const int N=1e5+10;
const int INF=0x3f3f3f3f;
long long a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,x,y,ans=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		i++;
	}
	if(a[x]==a[y]){
		ans+=1;
	}
    
	
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
