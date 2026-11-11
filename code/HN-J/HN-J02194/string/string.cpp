#include<bits/stdc++.h>
using namespace std;
struct x{
	int b;
	char c;
}a[101];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,h=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c;
	
	}
	for(int i=1;i<=n;i++){
		if(a[i].c==a[n].c){
			cout<<0;
			break;
		}
		else if(a[i].b==a[i+1].b){
			cout<<a[i].b*(n-2);
			break;
		}
		else if(a[i].b>=a[i+1].b){
		 	cout<<a[i].b;
		 	break;
		}
		else if(a[i].b<a[i+1].b){
			h=a[i+1].b;
			cout<<h-1;
			break;
		}
	}

}
