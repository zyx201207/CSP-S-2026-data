#include<bits/stdc++.h>
using namespace std;
int a[800005];
int bf[800005];
char c[800005];
long long an=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	int l=1,r=n;
	while(l<r){
		if(!a[l]){
			l++;
		}
		if(!a[r]){
			r--;
		}
		if(l==r){
			break;
		}
		if(c[l]!=c[r]){
			an+=min(a[l],a[r]);
		}
		int t=min(a[l],a[r]);
		a[l]-=t;
		a[r]-=t;
	}
	cout << an;
	return 0;
}
