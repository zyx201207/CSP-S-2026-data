#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long a[200010];
	char c[200010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	long long ans=0;
	while(i<j){
		if(c[i]==c[j]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			else if(a[i]==a[j]){
				i++,j--;
				continue;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
		}
		else{
			if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else if(a[i]==a[j]){
				ans+=a[i];
				i++,j--;
				continue;
			}
			else if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
