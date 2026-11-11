#include<bits/stdc++.h>
using namespace std;
int n;
struct S{
	long long b;
	char c;
}a[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c;
		if(a[i].c==a[i-1].c){
			i--;
			n--;
			a[i].b+=a[i+1].b;
		}
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].b>a[r].b){
				ans+=a[l].b-a[r].b;
				a[l].b-=a[r].b;
				a[r].b=0;
				r--;
			}
			else if(a[l].b<a[r].b){
				ans+=a[r].b-a[l].b;
				a[r].b-=a[l].b;
				a[l].b=0;
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(a[l].b>a[r].b){
				ans+=a[l].b-a[r].b;
				a[l].b-=a[r].b;
				a[r].b=0;
				r--;
			}
			else if(a[l].b<a[r].b){
				ans+=a[r].b-a[l].b;
				a[r].b-=a[l].b;
				a[l].b=0;
				l++;
			}
			else{
				ans+=a[l].b;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
