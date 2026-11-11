#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d[200005][100],maxc=-1,z=0;
//int f(int n){
//	c=c/2;	
//	return c%2;
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>a>>b;
	for(long long i=0;i<a;i++){
		cin>>c;
		if(maxc<c){
			maxc=c;
		} 
	}
//	for(long long i=0;i<a;i++){
//		
//	} 
	cout<<maxc;
	return 0;
}
