#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int m;
	string s;
}a[200005];
ll n,ans,j=1,k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	k=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].s;
	}
	while(k>j){
		if(a[j].s==a[k].s and a[j].m==a[k].m){
		 	j++,k--;
		 	continue;
		}
		else if(a[j].s==a[k].s and a[j].m!=a[k].m){
			if(a[j].m>a[k].m){
				a[j].m-=a[k].m;
				k--;
			}else{
				a[k].m-=a[j].m;
				j++;
			}
		}else if(a[j].s!=a[k].s and a[j].m==a[k].m){
			ans+=a[j].m;
			j++,k--;
		}else{
			if(a[j].m>a[k].m){
				ans+=a[k].m;
				a[j].m-=a[k].m;
				k--;
			}else{
				ans+=a[j].m;
				a[k].m-=a[j].m;
				j++;
			}
		}
	}
	cout<<ans;
	return 0;
}
