#include<bits/stdc++.h>
using namespace std;
struct node{
	int a=0;
	char b=' ';
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,p=0,q;
	long long ans=0;
	cin>>n;
	node z[n];
	q=n-1;
	for(int i=0;i<n;i++){
		cin>>z[i].a>>z[i].b;
	}
	while(p<q){
		if(z[p].b==z[q].b){
			if(z[p].a>z[q].a){
				z[p].a-=z[q].a;
				q--;
			}
			else{
				z[q].a-=z[p].a;
				p++;
			}
		}
		else{
			if(z[p].a>z[q].a){
				z[p].a-=z[q].a;
				ans+=z[q].a;
				q--;
			}
			else{
				z[q].a-=z[p].a;
				ans+=z[p].a;
				p++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
