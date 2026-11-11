#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
unsigned long long ans,L;
int n;
struct node{
	long long s;
	char ch;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].ch;
		//L+=a[i].s;
	}
	long long l=1,r=n;
	long long la1=0,la2=0;
	while(l<=r){
		if(a[l].ch!=a[r].ch){
			if(a[l].s-la1>a[r].s-la2){
				ans+=a[r].s-la2;
				la1+=a[r].s-la2;
				la2=0;
				r--;
			}else if(a[l].s-la1==a[r].s-la2){
				ans+=a[l].s-la1;
				la1=la2=0;
				l++;
				r--;
			}else if(a[l].s-la1<a[r].s-la2){
				ans+=a[l].s-la1;
				la2+=a[l].s-la1;
				la1=0;
				l++;
			}
		}else{
			if(a[l].s-la1>a[r].s-la2){
				la1+=a[r].s-la2;
				la2=0;
				r--;
			}else if(a[l].s-la1==a[r].s-la2){
				la1=la2=0;
				l++;
				r--;
			}else if(a[l].s-la1<a[r].s-la2){
				la2+=a[l].s-la1;
				la1=0;
				l++;
			}			
		}
	}
	cout<<ans;
	return 0; 
}
