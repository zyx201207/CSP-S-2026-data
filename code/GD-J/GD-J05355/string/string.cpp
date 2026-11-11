#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=2e5+5;

int n;
int l,r;
ll a[N];
char c[N];
ull ans=0;


int main(){
	freopen ("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	//freopen("string6.in","r",stdin);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	
	l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			if(a[l]<a[r])ans+=a[l],a[r]-=a[l],l++;
			else ans+=a[r],a[l]-=a[r],r--;
		}
		else {
			if(a[l]<a[r])a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}
	}
	
	cout<<ans;
	
	
	
	return 0;
} 
