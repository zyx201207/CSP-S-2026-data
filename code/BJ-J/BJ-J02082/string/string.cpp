#include<bits/stdc++.h>
using namespace std;
struct hw{
	int x;
	char s;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	struct hw a[200001];
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].s;
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(a[1].x>a[2].x){
			cout<<a[2].x;
		}else if(a[1].x<a[2].x){
			cout<<a[1].x;
		}else{
			cout<<0;
		}
	}
	return 0;
}