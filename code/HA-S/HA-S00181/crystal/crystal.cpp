#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans=0,s1=1,s=0;
queue<long long> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	q.push(a[1]);
	s=a[1];
	for(int i=2;i<=n;i++){
		while(a[i]*s1-s>m){
			s-=q.front();
			s1--;
			q.pop();
		}
		q.push(a[i]);
		s+=a[i];
		s1++;
		ans=max(ans,s1);
		//cout<<s<<"  "<<s1<<"\n";
	}
	cout<<ans;
	return 0;
}

/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7


*/
