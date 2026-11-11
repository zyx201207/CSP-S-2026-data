#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=2e5+10;

ll n,l,r,a[N],b[N],ans=0;
char ch;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n,l=1,r=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>ch,b[i]=ch-'a'+1;
	while(l<r)
		if(b[l]!=b[r]){
			if(a[l]>a[r])
				a[l]-=a[r],ans+=a[r],r--;
			else{
				if(a[l]==a[r])
					ans+=a[r],l++,r--;
				else
					a[r]-=a[l],ans+=a[l],l++;
			}
		}else{
			if(a[l]>a[r])
				a[l]-=a[r],r--;
			else{
				if(a[l]==a[r])
					l++,r--;
				else
					a[r]-=a[l],l++;
			}
		}
	cout<<ans;
}
