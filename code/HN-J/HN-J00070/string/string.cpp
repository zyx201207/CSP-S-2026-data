#include<bits/stdc++.h>
using namespace std;
long long ans;
int a[200050];
char c[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
		int al=a[l],ar=a[r];
	while(l<r){
		al=a[l],ar=a[r];
		if(c[l]!=c[r]){
			if(al<ar){
				ans+=al;
				a[r]-=al;
				l++;
			}
			else if(al>ar){
				ans+=ar;
				a[l]-=ar;
				r--;
			}
			else{
				l++;
				r--;
				ans+=al;
			}
		}
		else{
			if(al>ar){
				r--;
				a[l]-=ar;
			}
			else if(al<ar){
				l++;
				a[r]-=al;
			}
			else{
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
