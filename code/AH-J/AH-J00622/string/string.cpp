#include<bits/stdc++.h>
using namespace std;
long long asd[25];
long long d;
long long minx=0;
long long ans=0;
long long q;
char a[25],f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>d>>f;
		q=f-'a'+1;
		asd[q]+=d;
		minx=max(minx,(long long )(f-'a'+1));
	}
	if(minx==1){
		cout<<0;
		return 0;
	}
	else{
		int l=1,r=minx;
		while(l>r){
			ans+=asd[l];
			d=abs(asd[l]-asd[r]);
			if((r-l)!=1){
				if(asd[l]>asd[r]){
					asd[r-1]-d;
				}
				else{
					asd[l+1]-d;
				}
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
