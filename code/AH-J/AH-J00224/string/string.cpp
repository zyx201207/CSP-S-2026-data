#include <bits/stdc++.h>
using namespace std;
long long n,sum=0,add=0;
stack <pair<long long,string> > a,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		string r;
		long long q;
		cin >> q >> r;
		sum+=q;
		a.push({q,r});
	}
	for (long long i=1;i<=sum/2;i++){
		if (a.top().first+i>sum/2){
			c.push({sum/2-i+1,a.top().second});
			a.top().first-=(sum/2-i+1);
			break;
		}
		c.push({a.top().first,a.top().second});
		i+=(a.top().first-1);
		a.pop();
	}
	if (sum%2!=0) a.top().first-=1;
	while (!a.empty()&&!c.empty()){
		if (a.top().second==c.top().second){
			if (a.top().first==c.top().first){
				a.pop();
				c.pop();
			}
			else if (a.top().first>c.top().first){
				a.top().first-=c.top().first;
				c.pop();
			}
			else{
				c.top().first-=a.top().first;
				a.pop();
			}
		}
		else{
			if (a.top().first==c.top().first){
				add+=a.top().first;
				a.pop();
				c.pop();
			}
			else if (a.top().first>c.top().first){
				add+=c.top().first;
				a.top().first-=c.top().first;
				c.pop();
			}
			else{
				add+=a.top().first;
				c.top().first-=a.top().first;
				a.pop();
			}
		}
	}
	cout << add;
	return 0;
}