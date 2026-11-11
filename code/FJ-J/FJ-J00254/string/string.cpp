#include<bits/stdc++.h>
using namespace std;
int n,l=1,r=0;
long long ans,x;
char y;
struct gg{
	long long b;
	char c;
}a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(a[r].c==y){
			a[r].b=a[r].b+x;
		}else{
			a[++r].b=x;
			a[r].c=y;
		}
	}
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].b>a[r].b){
				a[l].b=a[l].b-a[r].b;
				r--;
			}else if(a[l].b<a[r].b){
				a[r].b=a[r].b-a[l].b;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].b>a[r].b){
				ans=ans+a[r].b;
				a[l].b=a[l].b-a[r].b;
				r--;
			}else if(a[l].b<a[r].b){
				ans=ans+a[l].b;
				a[r].b=a[r].b-a[l].b;
				l++;
			}else{
				ans=ans+a[l].b;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
