#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int an[N];
char cn[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,r=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>an[i]>>cn[i];
	}
	for(int i=1,j=n;i<=j;){
		if(cn[i]!=cn[j]){
			r+=min(an[i],an[j]);
			if(an[i]>an[j])an[i]-=an[j],j--;
			else an[j]-=an[i],i++;
		}else if(an[i]!=an[j]){
			if(an[i]>an[j])an[i]-=an[j],j--;
			else an[j]-=an[i],i++;
		}else i++,j--;
	}
	cout<<r;
	return 0;
}

