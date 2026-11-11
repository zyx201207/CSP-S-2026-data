#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
		int n,m,max=-1,a;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			if(a>max){
				max=a;
			}
		}	
		cout<<max;
	return 0;
}
