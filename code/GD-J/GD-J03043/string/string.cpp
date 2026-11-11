#include<bits/stdc++.h>
using namespace std;
struct sp{
	int s;
	char p;
};
sp a[5000];
int main(){
	freopen("D:/GD-J03043/string/string.in" , "r" , stdin);
	freopen("D:/GD-J03043/string/string.out" , "w" , stdout);
	int n;
	cin>>n;
	
	string x , y;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].p;
		
		for(int j=1;j<=a[i].s;j++){
			x+=a[i].p;
		}
		
	}
	for(int i=n;i>=1;i--){
		
		for(int j=1;j<=a[i].s;j++){
			y+=a[i].p;
		}
		
	}
	
	int cnt=0;
	
	if(x.size()%2==1){
		for(int i=0;i<=(x.size()+1)/2;i++){
			if(x[i]!=y[i]){
				cnt++;
			}
		}
	}else if(x.size()%2==0){
		for(int i=0;i<=(x.size())/2;i++){
			if(x[i]!=y[i]){
				cnt++;
			}
		}
	}
	cout<<cnt;
}
