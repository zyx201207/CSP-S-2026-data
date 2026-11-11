#include <bits/stdc++.h> 
using namespace std;
struct goog{
	string c;
	long long a;
}shu[1000005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "W", stdout);
	long long n;
	string s;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	else if(n==2){
		cout<<0;
		return 0;
	}
	for(long long i=0; i<n; i++){
		cin>>shu[i].a>>shu[i].c;
	}
	long long y=0, sum=0;
	while(y<n){
		if(shu[y].c[0]!=shu[n].c[0]){
			sum+=max(shu[y].a, shu[n].a)-min(shu[y].a, shu[n].a);
		}
		if(shu[y].a>shu[n].a){
			shu[y].a-=shu[n].a;
			n--;
		}
		else if(shu[y].a==shu[n].a){
			y++, n--;
		}
		else{
			shu[n].a-=shu[y].a;
			y++;
		}
	}
	cout<<sum;
	return 0;
}
