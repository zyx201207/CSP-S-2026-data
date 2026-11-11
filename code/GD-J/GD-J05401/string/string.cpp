#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int n;
int l;
int tot;
int sum;
struct node{
	int id;
	int s;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		a[i].id=i;
		l+=a[i].s;
	}
//	int mid=(l-1)/2;
	int i=1,j=n;
	while(i<=j){
		if(a[i].c==a[j].c){
			if(a[i].s>a[j].s){
				a[i].s-=a[j].s;
				j--;
			}else if(a[i].s<a[j].s){
				a[j].s-=a[i].s;
				i++;
			}else if(a[i].s==a[j].s){
				i++,j--;
			}
		}else{
			if(a[i].s>=a[j].s){
				sum+=a[j].s;
				a[i].s-=a[j].s;
				j--;
			}else{
				sum+=a[i].s;
				a[j].s-=a[i].s;
				i++;
			}
		}
	}cout<<sum;
    return 0;
}
//所有大样例过于9：19 
