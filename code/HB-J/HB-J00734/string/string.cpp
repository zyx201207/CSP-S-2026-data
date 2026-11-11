/*#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sug=2e5+5;
int n,sum,ans;
int a[sug],l[sug],r[sug];
char c[sug];
signed main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[i]+=a[i-1];
		l[i]=a[i-1];
		r[i]=a[i];
	}
	sum=a[n];
	for(int i=1,j=n;i<=sum/2&&j>=sum/2;){
		if(r[i]>=sum-l[j]&&l[i]<=sum-r[j]){
			if(c[i]==c[j]) ans+=(r[j]-l[j]);
			j--;
		}
		else if(r[i]<=sum-l[j]&&l[i]>=sum-r[j]){
			if(c[i]==c[j]) ans+=(r[i]-l[i]);
			i++;
		}
		else if(r[i]>=sum-r[j]&&l[i]<=sum-r[j]){
			if(c[i]==c[j]) ans+=(r[i]-sum+r[j]);
			i++;
		}
		else if(r[i]>=sum-l[j]&&l[i]<=sum-l[j]){
			if(c[i]==c[j]) ans+=(sum-l[j]-l[i]);
			j--;
		}else if(r[i]<sum-r[i]) i++;
		else j--;
		
	}
 	cout<<sum/2-ans;
	return 0;
	jinlile
	* xncvn
	* 
	* erwet
	* 
	* dfs
}*/
#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int sug=3e7+5;
int n,sum,ans;
int a[sug];
char num[sug];
char c[sug];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			num[j+sum]=c[i];
		}
		sum+=a[i];
	}
	sum++;
	for(int i=1;i<=sum/2;i++){
		if(num[i]!=num[sum-i]) ans++;
 	}
 	cout<<ans;
	return 0;
}
