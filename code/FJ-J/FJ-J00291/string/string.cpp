#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s[N];
int n,x[N];
long long cnt,sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>s[i];
		cnt+=x[i];
	}
	int i=1,j=n;
	while(sum<=cnt/2&&i<j){
		sum+=min(x[i],x[j]);
		if(s[i]!=s[j]){
			if(x[i]>x[j]){
				ans+=x[j];
				x[i]-=x[j];
				j--;
			}else if(x[i]<x[j]){
				ans+=x[i];
				x[j]-=x[i];
				i++;
			}else{
				ans+=x[i];
				i++;
				j--;
			}
		}else{
			if(x[i]>x[j]){
				x[i]-=x[j];
				j--;
			}else if(x[i]<x[j]){
				x[j]-=x[i];
				i++;
			}else {
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

