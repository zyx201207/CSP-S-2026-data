#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+5;
int n;
long long int ans=0,a[N],ovo=0; 
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		ovo+=a[i];
	}
	long long int l=1,sum=0,r=n;
	while(ans<floor(ovo/2)){
		ans+=a[l];
		long long int t=a[l];
		while(t>0){
			long long int awa=t;
			if(s[l]==s[r]){
				t=max(0LL,t-a[r]);
				if(t<=0){
					a[r]-=awa;
					break;
				}
				else{
					a[r]=0;
					r--;
				}
			}
			else{
				t=max(0LL,t-a[r]);
				if(t<=0){
					sum+=awa;
					a[r]-=awa;
					break;
				}
				else{
					sum+=a[r];
					a[r]=0;
					r--;
				}
			}
		}
		l++;
	}
	cout<<sum;
	return 0;
}
