#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,len;
struct node{
	long long x;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		len+=a[i].x;
	}
	int i=1,j=n;
	while(i<j){
		if(a[i].x!=a[j].x){
			if(a[i].x>a[j].x){
				if(a[i].c!=a[j].c){
					ans+=a[j].x;
				}
				a[i].x-=a[j].x;
				j--;
			}
			else{
				if(a[i].c!=a[j].c){
					ans+=a[i].x;
				}
				a[j].x-=a[i].x;
				i++;
			}
		}
		else{
			if(a[i].c!=a[j].c){
				ans+=a[i].x;
			}
			i++;
			j--;
		}
		//cout<<"ans:"<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}
