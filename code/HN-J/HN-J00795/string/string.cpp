#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int n;char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].n>>a[i].c;
	}
	for(int i=1,j=n;i<=j;){
		if(a[i].c==a[j].c){
			if(a[i].n>a[j].n){
				a[i].n-=a[j].n;
				a[j].n=0;
				j--;
			}else if(a[i].n<a[j].n){
				a[j].n-=a[i].n;
				a[i].n=0;
				i++;
			}else if(a[i].n==a[j].n){
				a[j].n=0;
				a[i].n=0;
				i++;
				j--;
			}
		}else{
			if(a[i].n>a[j].n){
				ans+=a[j].n;
				a[i].n-=a[j].n;
				a[j].n=0;
				j--;
			}else if(a[i].n<a[j].n){
				ans+=a[i].n;
				a[j].n-=a[i].n;
				a[i].n=0;
				i++;
			}else if(a[i].n==a[j].n){
				ans+=a[i].n;
				a[j].n=0;
				a[i].n=0;
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

2
2 a
3 a
*/
