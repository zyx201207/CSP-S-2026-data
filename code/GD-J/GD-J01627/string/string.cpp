#include <bits/stdc++.h>
using namespace std;
long long a[200005], b[200005];
char c[200005];
long long sum, jl, ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		b[i]=b[i-1]+a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(jl < sum/2 && b[i] <= sum/2){
			long long l=sum-jl-a[i]+1, r=sum-jl, x, y;
			x=lower_bound(b+1, b+n+1, l)-b;
			y=lower_bound(b+1, b+n+1, r)-b;
			
			if(x==y){
				if(c[i]!=c[x]) ans+=a[i]; 
				jl=b[i];
				continue;
			}
			for(int j=x;j<=y;j++){
				if(j==x){
					if(c[i]!=c[j]){
						ans+=b[j]-l+1; 
					}
				}
				else if(j==y){
					if(c[i]!=c[j]){
						ans+=r-b[j-1];
					}
				}
				else{
					if(c[i]!=c[j]){
						ans+=a[j];
					}
				}
			}
			jl=b[i];
		}
		else if(jl < sum/2 && b[i] > sum/2){
			if(sum%2){
				if((sum/2-1)-(b[i-1]+1)+1<=b[i]-(sum/2+1)+1){
					break;
				}
			}
			else{
				if((sum/2)-(b[i-1]+1)+1<=b[i]-(sum/2+1)+1){
					break;
				}
			}
			long long l=b[i]+1, r=sum-jl, x=i+1, y;
			x=i+1;
			y=lower_bound(b+1, b+n+1, r)-b;
			if(x==y){
				if(c[i]!=c[x]) ans+=r-l+1; 
				continue;
			}
			for(int j=x;j<=y;j++){
				if(j==x){
					if(c[i]!=c[j]){
						ans+=b[j]-l+1; 
					}
				}
				else if(j==y){
					if(c[i]!=c[j]){
						ans+=r-b[j-1];
					}
				}
				else{
					if(c[i]!=c[j]){
						ans+=a[j];
					}
				}
			}		
			break;
		}
		else{
			break;
		}
	}
	cout << ans;
	return 0;
} 
