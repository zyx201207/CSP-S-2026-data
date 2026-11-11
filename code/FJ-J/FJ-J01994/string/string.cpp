#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct yu{
	int a;
	char c;
}a[200005];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i].a>>a[i].c;
	int l=1;
	int r=n;
	while (l<r){
		//cout<<ans<<"\n";
		if (a[l].a>=a[r].a){
			int t=a[l].a-a[r].a;
			if (a[r].c!=a[l].c)
			ans+=a[r].a;
			if (t>0){
				//cout<<"ok";
				r--;
				while (t!=0){
					if (a[r].a==0)r--;
					if (a[r].c!=a[l].c){
						a[r].a--;
						ans++;
					}
					else{
						a[r].a--;
					}
					t--;
				}
			}
			l++;
			//cout<<l<<" "<<r<<"\n";
		}
		else{
			int t=a[r].a-a[l].a;
			if (a[r].c!=a[l].c)
			ans+=a[l].a;
			if (t>0){
				l++;
				while (t!=0){
					if (a[l].a==0)l++;
					if (a[l].c!=a[r].c){
						a[l].a--;
						ans++;
					}
					else{
						a[l].a--;
					}
					t--;
				}
			}
			r--;
		}
	}
	cout<<ans;
}
/*
3
2 a
2 b
1 c
*/
