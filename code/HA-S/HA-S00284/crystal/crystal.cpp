#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxc=0;
bool cmp(int x,int y){
	return x>y;
}


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	ll a[500005];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		int c=0;
		int ma=m;
		for(int j=i;j<n&&ma>=0;j++){
			if(ma-(a[i]-a[j])>=0){
				c++;
				ma-=(a[i]-a[j]);
			}
			else break;
		}
		maxc=max(maxc,c);
	}
	cout<<maxc;

	
		
	return 0;
}