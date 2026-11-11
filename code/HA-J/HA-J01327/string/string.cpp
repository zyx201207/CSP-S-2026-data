#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long n,i,j,ans;
struct node{long long num; char c;}a[200005];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int ii=1; ii<=n; ii++){
		cin >> a[ii].num >> a[ii].c;
	}
	
	i=1,j=n;
	while(i<j){
		if(a[i].num>a[j].num && a[i].c!=a[j].c){
			ans+=a[j].num;
			a[i].num-=a[j].num;
			j--;
		}else if(a[i].num<a[j].num && a[i].c!=a[j].c){
			ans+=a[i].num;
			a[j].num-=a[i].num;
			i++;
		}else if(a[i].num==a[j].num && a[i].c!=a[j].c){
			ans+=a[i].num;
			i++,j--;
		}else if(a[i].num>a[j].num && a[i].c==a[j].c){
			a[i].num-=a[j].num;
			j--;
		}else if(a[i].num<a[j].num && a[i].c==a[j].c){
			a[j].num-=a[i].num;
			i++;
		}else if(a[i].num==a[j].num && a[i].c==a[j].c){
			i++,j--;
		}
	}


	
	cout << ans;

	return 0;
}

