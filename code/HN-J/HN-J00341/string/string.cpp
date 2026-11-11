#include<bits/stdc++.h>
using namespace std;
struct node{
	int g;
	char s;
};
node a[200005];
//int d=0;
__int128 ans;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
//2 a 
//2 b
//1 c
//aabbc
//abc
//aaabbb 
	int n;
	cin>>n;
//	cout<<n;
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
bool f=false;
char c;
	for(int i=1;i<=n;i++){
		cin>>a[i].g>>a[i].s;
		if(i==1){
			c=a[i].s;
		}
		if(a[i].s!=c) f=true;
		
	}
	if(n%2==0){
		for(int i=1;i<=n/2;i++){
			if(a[i].s!=a[n+1-i].s||a[i].g!=a[n+1-i].g){
			//	cout<<'1'<<endl;
				if(a[i].s!=a[n+1-i].s){
					ans+=a[n+1-i].g;
					a[n+1-i].s=a[i].s;
				}else if(a[i].g!=a[n+1-i].g&&f){
					ans+=abs(a[i].g-a[n+1-i].g);
				}else if(!f){
					cout<<0<<endl;
					return 0;
				}
			}
		}
	}else{
	for(int i=1;i<=n;i++){
			if(a[i].s!=a[n+1-i].s||a[i].g!=a[n+1-i].g){
			//	cout<<'1'<<endl;
				if(a[i].s!=a[n+1-i].s){
					ans+=a[n+1-i].g;
					a[n+1-i].s=a[i].s;
				}else if(a[i].g!=a[n+1-i].g&&f){
					ans+=abs(a[i].g-a[n+1-i].g);
				}else if(!f){
					cout<<0<<endl;
					return 0;
				}
			}
		}	
	}
	int k=0;
	char o[120];
	while(ans!=0){
		o[k++]=char(ans%10+'0');
		ans/=10;
	}
	for(int i=k-1;i>=0;i--){
		cout<<o[i];
	}
	return 0;
}
