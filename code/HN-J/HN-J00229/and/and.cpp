#include "iostream"
#include "algorithm"
using namespace std;
const int N=2*1e5+5;
int s[N],ans;
int n,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	
	if(k==n){
		ans=s[0];
		for(int i=1;i<n;i++){
			ans&=s[i];
		}
		cout<<ans;
		return 0;
	}
	else if(k==1){
		cout<<s[n-1];
		return 0;
	}
	else if(k==2){
		for(int i=0;i<n-k;i++){
			for(int j=i;j<n;j++){
				ans=max(ans,s[i]&s[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	else cout<<0;
}
