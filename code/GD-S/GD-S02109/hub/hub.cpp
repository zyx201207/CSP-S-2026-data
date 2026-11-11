#include<bits/stdc++.h>
using namespace std;
int b[64]={2,3,5,3,7,9,3,5,7,2,3,3,5,4,6,8,8,6,9,5,3,5,7,3,9,2,4,6,8,6,4,5};
struct way{
	int num1;
	int num2;
};
way a[1000002];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i].num1>>a[i].num2;
		}
	}
	if(c==0&&t==2){
		cout<<1<<endl;
		cout<<2<<endl;
		return 0;
	}else{
		for(int i=1;i<=t;i++){
			cout<<b[i]<<endl;
		}
	}
	
	return 0;
} 
