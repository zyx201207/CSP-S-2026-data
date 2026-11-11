#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*1e5+50;
char s[MAXN];
int num[MAXN],n;
unsigned long long ans;
int main(){
	memset(s,' ',sizeof(s));
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>s[i];
	}
	int k=1,e=n;
	while(!(k==e)){	
		if(s[k]==s[e]){
			int minx=min(num[k],num[e]);
			num[k]-=minx;
			num[e]-=minx;
		}
		else{
			int minx=min(num[k],num[e]);
			num[k]-=minx;
			num[e]-=minx;
			ans+=minx;
		}
		if(num[k]==0) k++;
		if(num[e]==0) e--;
		if(e-k==1) break; 
	}
	if(s[k]!=s[e]){
		ans+=min(num[k],num[e]);
	}
	cout<<ans;
	return 0;
}
