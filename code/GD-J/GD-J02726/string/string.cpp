#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,a[N],ans;
char c[N];
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];cin>>c[i];
		s+=c[i];
	}
	s=' '+s;
	int l=s.length()-1;
	int i=1,j=l;
	while(i<=j) {
		if(s[i]!=s[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			} 
			else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
			else{
				ans+=a[i];
				i++;j--;
			}
		}
		else{
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
