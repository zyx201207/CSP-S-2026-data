//GZ-J00429 贵州省铜仁市印江县木黄中学 银朗 
#include <iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=i;i<=n;i++){
		int  x;
		cin>>x;
		string s;
		while(x!=0){
			s=x%2;
			x/=2;
		}
		for(int i=s.size()-1;i>=0;i--){
			x=s[i];
		}
		for(i=s.size()-1;i>=0;i--){
		   cout<<max(x[i],x[i+1] );
		} 
	}
	retern 0;
}
