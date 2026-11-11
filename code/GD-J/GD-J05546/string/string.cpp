#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long a[maxn],ans,L;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		s+=c;
		L+=a[i];
	}
	int i=1,j=n;
	while(i<j){
		if(s[i-1]!=s[j-1]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else if(a[i]==a[j]){
				ans+=a[i];
				a[i]=a[j]=0;
				i++,j--;
			}
			else ans+=a[i],a[j]-=a[i],i++;
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			else if(a[i]==a[j]){
				a[i]=a[j]=0;
				i++,j--;
			}
			else a[j]-=a[i],i++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

