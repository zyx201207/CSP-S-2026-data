#include<bits/stdc++.h>
using namespace std;

int n,k,sum,ans; 
int a[200005],b[200005];
bool c=1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=100;i>=1;i--){
		if(b[i]>0){
			if(c==1){
				ans=i;
			}
			c=0;
			while(b[i]--){
				sum++;
				if(sum>k){
					cout<<ans<<endl;
					return 0;
				}
				ans=i&ans;
			}
		}
	}
	return 0;
}
