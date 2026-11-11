#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char b;
};
int n;
int l,r;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<node>v(n+5);
	l=1;r=n;
	for(int i=1;i<=n;i++){
		long long a;char b;
		cin>>a>>b;
		v[i].a=a;v[i].b=b;
	}
	while(r>l){
		node a=v[l];int ia=l;
		node b=v[r];int ib=r;
		bool q=a.b!=b.b; 
		if(a.a==b.a){
			if(q)sum+=a.a;
			r--;
			l++;
		}
		else if(a.a>b.a){
			if(q)sum+=b.a;
			a.a=a.a-b.a;
			r--;
		}
		
		else if(a.a<b.a){
			if(q)sum+=a.a;
			b.a=b.a-a.a;
			l++;
		}
		
		v[ia]=a;
		v[ib]=b;
	}
	cout<<sum;
	return 0;
}

