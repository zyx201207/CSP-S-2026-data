#include<iostream>
#include<cstdio>
using namespace std;
struct node{
	int m;
	char c;
}a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned long long ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].m<a[r].m){
			if(a[l].c!=a[r].c){
				ans+=a[l].m;
			}
			a[r].m-=a[l].m;
			l++;
			continue;
		}
		else if(a[l].m==a[r].m){
			if(a[l].c!=a[r].c){
				ans+=a[l].m;
			}
			l++;
			r--;
			continue;
		}else{
			if(a[l].c!=a[r].c){
				ans+=a[r].m;
			}
			a[l].m-=a[r].m;
			r--;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
