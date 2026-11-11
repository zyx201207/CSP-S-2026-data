#include<bits/stdc++.h>
using namespace std;
struct node{
	int s;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	long long L=0;
	for (int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		L+=a[i].s;
	}
	long long ans=0;long long cnt=0,w=1;
//	cout<<L/2<<"\n";//
	for (int i=n;cnt<L/2;){
		if (a[i].c!=a[w].c) {
			if (a[i].s>a[w].s) {
				a[i].s-=a[w].s;
//				cout<<"aw="<<a[w].s<<"\n";//
				ans+=a[w].s; cnt+=a[w].s; w++;
			}
			else if (a[i].s<a[w].s) {
				a[w].s-=a[i].s;
				
				ans+=a[i].s;
				cnt+=a[i].s; i--;
			}
			else if (a[i].s==a[w].s) {
				ans+=a[w].s; cnt+=a[w].s; w++; i--;
			}
//			cout<<ans<<" "<<cnt<<"\n";//
		}
		else if (a[i].c==a[w].c) {
			if (a[i].s>a[w].s) {
				a[i].s-=a[w].s;
				cnt+=a[w].s; w++;
			}
			else if (a[i].s<a[w].s) {
				a[w].s-=a[i].s;
				cnt+=a[i].s; i--;
			}
			else if (a[i].s==a[w].s) {
				cnt+=a[w].s; w++; i--;
			}
//		cout<<ans<<" "<<cnt<<"\n";//
		}
	}
	cout<<ans<<"\n";
	return 0;
}

