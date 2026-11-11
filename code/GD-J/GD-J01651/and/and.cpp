#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=-1;
	int c,b;
	int a[200005],s[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]&a[j]>sum){
				sum=a[i]&a[j];
				c=i;
				b=j;
			}
		}
	}
	s[c]=1;
	s[b]=1;
	int d=2;
	while(d<m){
		int f=-1;
		for(int i=0;i<n;i++){
			if(s[i]==0){
				if(f==-1) f=i;
				else if(sum&a[f]<sum&a[i]){
					f=i;
				}
			}
		}
		s[f]=1;
		sum=sum&a[f];
		d++;
	}
	cout<<sum;
	return 0;
} 
