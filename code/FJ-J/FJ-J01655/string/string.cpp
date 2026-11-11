#include<bits/stdc++.h>
using namespace std;
long long n,h,j,k,l,p;
char e[100005],b[100005],d[100005];
struct node{
	long long a;
	char c;
}m[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i].a>>m[i].c;
		h+=m[i].a;
	}
	k=m[j].a-1;
	for(int i=0;i<h;i++){
		if(i>k){
			j++;
			k+=m[j].a;
		}
		e[i]=m[j].c;
	}   
	j=0;
	l=h/2;
	for(int i=0;i<l;i++){
		b[i]=e[i];
	}
	for(int i=h-1;i>=l;i--){
		d[j]=e[i];
		j++;
	}
	for(int i=0;i<l;i++){
		if(b[i]!=d[i]) p++;
	}
	cout<<p;
	return 0;
}