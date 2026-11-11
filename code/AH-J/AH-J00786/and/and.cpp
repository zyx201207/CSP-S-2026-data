#include <bits/stdc++.h>
using namespace std;
string a[1000010];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long int n=0,m=0,x=0,w=INT_MAX,y,max=0,max1=0;
	cin>>n>>m;
	if(m==1){
		for(int i=0;i<n;i++){
		cin>>y;
		if(y>x){
			x=y;
		}	
		}
		cout<<x;
	}
	if(m==n){
		for(int i=0;i<n;i++){
			cin>>y;
			x+=y;
		}
		cout<<x;
	}
	if(m==n-1){
		for(int i=0;i<n;i++){
			cin>>y;
			if(w>y){
				w=y;
			}
			x+=y;
		}
		cout<<x-m;
	}
	if(m=2){
		for(int i=0;i<n;i++){
		cin>>y;
			if(max<y){
				max=y;
			}
			if(y>max and y>max1){
				max1=y;
			}
		}
		cout<<max+max1;
	}
	return 0;
}
