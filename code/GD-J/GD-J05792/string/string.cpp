#include<bits/stdc++.h>
using namespace std;
long long n,y=0,p=0;
struct aa{
	long long a;
	char b;
}o[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>o[i].a>>o[i].b;
	}
	for(int i=0;i<n-1;i++){
		if(o[i].b==o[i+1].b){
			y=1;
		}else{
			y=0;
			break;
		}
	}
	if(y==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		p+=o[i].a;
	}
	cout<<p/2;
	return 0;
} 
