#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
int n,m,s;
int a[200005];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
	s=a[1];
	for(int i=1;i<=n;i++){
		s&=a[i];
	}
		cout<<s;
		return 0;
	}
	if(m==1){
		int max_=-1;
		for(int i=1;i<=n;i++){
			max_=max(max_,a[i]);
		}
		cout<<max_;
		return 0;
	}
	if(m==n-1){
		int max_=0;
		for(int i=1;i<=n;i++){
			s=a[(i+1)%n];
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				s&=a[j];
			}
			max_=max(max_,s);
		}
		cout<<s;
		return 0;
	}
	
	return 0;
}
//Trick||Treat!
