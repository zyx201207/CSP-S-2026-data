#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	char c;
}a[200010];

int n;
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int i=1,j=n;
	while(j>i){
		if(a[i].c==a[j].c){
			if(a[i].x<a[j].x){
				ans+=a[j].x-a[i].x;
				a[i+1].x-=(a[j].x-a[i].x);
			}
			else{
				if(a[i].x>a[j].x){
					ans+=a[i].x-a[j].x;
					a[j-1].x-=(a[i].x-a[j].x);
				}
			}
			i++;
			j--;
		}
		else{
			if(a[i].x>a[j].x){
				ans+=a[i].x;
				a[j-1].x-=(a[i].x-a[j].x);
			}
			else{
				ans+=a[j].x;
				a[i+1].x-=(a[j].x-a[i].x);
			}
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
