#include<bits/stdc++.h>
using namespace std;
struct st{
	int x;
	char c;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		s+=a[i].x;
	} 
	long long ans=0;
	long long ts=0,i=1,j=n;
	bool f=0;
	while(i<j){
		if(a[i].x>a[j].x){
			if(a[i].c!=a[j].c){
				ans+=a[j].x;
			}
			ts+=a[j].x;
			a[i].x-=a[j].x;
			a[j].x=0;
			j--;
		}else if(a[i].x<a[j].x){
			if(a[i].c!=a[j].c){
				ans+=a[i].x;
			}
			ts+=a[i].x;
			a[j].x-=a[i].x;
			a[i].x=0;
			i++;
		}else{
			if(a[i].c!=a[j].c){
				ans+=a[i].x;
			}
			a[i].x=0;
			a[j].x=0;
			i++;
			j--;
			ts+=a[i].x;
		}
	}
	cout<<ans;
	return 0;
}
