#include<iostream>
#include<cstdio>
using namespace std;

struct node{
	char c;
	int x;
} a[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s;
	int n; cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].c;
	}
	long long cnt=0;
	int l=0,r=n-1;
	
	while(l<r){
		if(a[l].x<a[r].x){
			if(a[l].c!=a[r].c){
				cnt+=a[l].x;
			}
			a[r].x-=a[l].x;
			l++;
		} else {
			if(a[l].c!=a[r].c){
				cnt+=a[r].x;
			}
			a[l].x-=a[r].x;
			r--;
			if(a[l].x==0)l++;
		}
	}
	cout<<cnt;
	
	
	return 0;
}
