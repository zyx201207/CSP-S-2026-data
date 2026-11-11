#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int num;
	char c;
}a[N]; 
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].num<a[r].num){
			a[r].num-=a[l].num;
			if(a[l].c!=a[r].c){
				ans+=a[l].num;
			}
		}
		else if(a[l].num==a[r].num){
			if(a[l].c!=a[r].c){
				ans+=a[l].num;
			}
			--r;
		}
		else{
			while(a[l].num>0){
				if(a[l].num<a[r].num){
					a[r].num-=a[l].num;
					if(a[l].c!=a[r].c){
						ans+=a[l].num;
					}
					a[l].num=0;
				}
				else if(a[l].num==a[r].num){
					if(a[l].c!=a[r].c){
						ans+=a[l].num;
					}
					a[l].num=0;
					--r;
				}
				else{
					if(a[l].c!=a[r].c){
						ans+=a[r].num;
					}
					a[l].num-=a[r].num;
					--r;
				}
			}
		}
		++l;
	}
	cout<<ans;
	return 0;
}
