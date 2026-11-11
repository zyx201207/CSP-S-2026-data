#include<bits/stdc++.h>
using namespace std;
struct st{
	char c;
	int b;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int x,ans=0,s=0;
	cin>>x;
	st a[10007];
	for(int i=0;i<x;i++){
		cin>>a[i].b>>a[i].c;
	}
	for(int i=0;i<x;i++){
		s+=a[i].b;
	}
	int y;
	if(x%2==1){
		y=(x+1)/2;
	}
	else{
		y=x/2+1;
	}
	for(int i=0,j=x;i<=y;i++,j--){
		if(a[i].c==a[j].c){
			if(a[i].b!=a[j].b){
				if(a[i].b>a[j].b){
					ans+=a[i].b-a[j].b;
				}
				else{
					ans+=a[j].b-a[i].b;
				}
			}
		}
		else{
			if(a[i].b<a[j].b){
				ans+=a[i].b;
			}
			else{
				ans+=a[j].b;
			}
		}
	}
	cout<<ans;
	return 0;
} 
