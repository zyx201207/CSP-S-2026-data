#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,mid,ans;
struct node{
	long long b,m;
	char c;
}a[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i].m=cnt;
		cin>>a[i].b>>a[i].c;
		cnt+=a[i].b;
		
	}
	mid=(cnt+1)/2;
	for(int i=1,j=n;;){//cout<<ans<<' ';
	if(a[i].m+a[i].b!=a[j].m&&i!=j){
		
		if(a[i].c!=a[j].c){
			if(a[i].b>a[j].b){
				ans+=a[j].b;
				a[i].m+=a[j].b;
				a[i].b-=a[j].b;
				j--;
			}else if(a[i].b<a[j].b){
				ans+=a[i].b;
				a[j].b-=a[i].b;
				i++;
			}else{
				ans+=a[i].b;
				i++;
				j--;
			}
			//cout<<'a'<<' ';
		}else{
			if(a[i].b>a[j].b){
				a[i].m+=a[j].b;
				a[i].b-=a[j].b;
				j--;
			}else if(a[i].b<a[j].b){
				a[j].b-=a[i].b;
				i++;
			}else{
				i++;
				j--;
			}
		//	cout<<'b'<<' ';
		}
	}else{
		if(i!=j){
		if(a[i].c!=a[j].c)ans+=min(a[i].b,a[j].b);
		}
		cout<<ans;
		return 0;
	}
	}
	return 0;
}
