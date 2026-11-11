#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long a[N+1];
char c[N+1];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	int lBound=1,rBound=n;
	while(lBound<rBound){
		if(c[lBound]==c[rBound]){
			if(a[lBound]==a[rBound]){
				lBound++;
				rBound--;
			}
			else if(a[lBound]<a[rBound]){
				a[rBound]-=a[lBound];
				lBound++;
			}
			else if(a[lBound]>a[rBound]){
				a[lBound]-=a[rBound];
				rBound--;
			}
		}
		else if(c[lBound]!=c[rBound]){
			if(a[lBound]==a[rBound]){
				ans+=a[lBound];
				lBound++;
				rBound--;
			}
			else if(a[lBound]<a[rBound]){
				ans+=a[lBound];
				a[rBound]-=a[lBound];
				lBound++;
			}
			else if(a[lBound]>a[rBound]){
				ans+=a[rBound];
				a[lBound]-=a[rBound];
				rBound--;
			}
		}
	}
	cout<<ans;
//	cerr<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
