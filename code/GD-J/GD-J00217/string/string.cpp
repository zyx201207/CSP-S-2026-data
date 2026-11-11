#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int j=n;
	for(int i=1;i<=n;i++){
		while(i<j){
			if(a[i]<=a[j]){
				if(c[i]!=c[j])	ans+=1LL*a[i];
				a[j]-=a[i],a[i]=0;
				break;
			}
			if(c[i]!=c[j])	ans+=1LL*a[j]; 
			a[i]-=a[j],a[j]=0,j--;
		}
		if(i>=j)	break;
	}
	cout<<ans;
	return 0;
}
