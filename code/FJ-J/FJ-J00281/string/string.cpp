#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2*1e5+5;
int n,a[N],ans=0,len,last=-1;
char c[N];
string s;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1]>>c[1];
	if(a[1]>=100000000){
		for(int i=2;i<=n;i++){
			cin>>a[i]>>c[i];
		}
		for(int i=1;i<=n+1/2;i++){
			if(last==-1)last=i;
			if(c[last]!=c[n-i+1]){
				if(a[last]==a[n-i+1])ans+=a[last];
				else if(a[last]>a[n-i+1]){
					ans+=a[n-i+1];
					a[last]-=a[n-i+1];
					a[n-i+1]=0;
	//				cout<<i<<" "<<ans<<endl;
				}
				else if(a[last]<a[n-i+1]){
					ans+=a[last];
					a[n-i+1]-=a[last];
					a[last]=0;
	//				cout<<i<<" "<<ans<<endl;
				}
			}
			if(a[last]==0)last=-1;
		}
	}
	else{
		for(int i=1;i<=a[1];i++){
			s+=c[1];
		}
		for(int i=2;i<=n;i++){
			cin>>a[i]>>c[i];
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		len=s.size();
		for(int i=0;i<len/2;i++){
			if(s[i]!=s[len-i-1]){
	//			cout<<s[len-i-1]<<"->"<<s[i]<<endl;
				ans++;
				s[len-i-1]=s[i];
			}
		}
	}
	cout<<ans;
	return 0;
}

/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

