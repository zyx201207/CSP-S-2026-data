#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
ll num[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			if(num[l]==num[r])l++,r--;
			else if(num[l]<num[r]){
				num[r]-=num[l];
				l++;
			}
			else if(num[l]>num[r]){
				num[l]-=num[r];
				r--;
			}
		}
		else{
			ans+=min(num[l],num[r]);
			if(num[l]==num[r])l++,r--;
			else if(num[l]<num[r]){
				num[r]-=num[l];
				l++;
			}
			else if(num[l]>num[r]){
				num[l]-=num[r];
				r--;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
}

