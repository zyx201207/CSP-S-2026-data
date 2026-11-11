#include<bits/stdc++.h>
using namespace std;
int a[200005];char b[200005];long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int i=0,j=n+1,l=0,r=0;
	while(i<=j){
		
		if(l==0&&i+1<j){
			i++;
			l+=a[i];
		}
		if(r==0&&j-1>i){
			j--;
			r+=a[j];
		}
		//cout<<i<<' '<<j<<' '<<l<<' '<<r<<endl;
		if(b[i]==b[j]){
			if(l>=r){
				l-=r;
				r=0;
			}
			else{
				r-=l;
				l=0;
			}
		}
		else{
			if(l>=r){
				ans+=r;
				l-=r;
				r=0;
			}
			else{
				ans+=l;
				r-=l;
				l=0;
			}
		}
		if(i+1==j){
			break;
		}
	}
	cout<<ans;
	return 0;
}
