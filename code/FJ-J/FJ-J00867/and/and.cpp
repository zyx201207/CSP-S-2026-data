#include<bits/stdc++.h>
using namespace std;
int n;
struct q{
	bool a[31];
	int m;
}s[200000];
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		s[i].m=x;
		int len=-1;
		while(x!=0){
			s[i].a[++len]=x%2;
			x/=2;
		}
		
	} 
	return 0;
}
