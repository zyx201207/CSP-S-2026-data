#include<bits/stdc++.h>
using namespace std;
long long i,a,b,j,r,l,k;
long long q[100000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(i=0;i<a;i++){
		cin>>q[i];
	}
	sort(q,q+a);
	r=a-1;
	while(r!=l){
		j=(l+r)/2+1;
		
		i=0;
		k=b;
		while(j>=i){
			b-=q[j]-q[i];
			i++;
		}
		if(b<0){
			r=j;
		}
		if(b>0){
			l=j;
		}
		if(b==0){
			cout<<j+1;
			return 0;

		}
		b=k;
		//cout<<j<<" "<<r<<" "<<l<<endl;
	}

	while(q[j+1]==q[j+2])
	{
		j++;
	}
	cout<<j+1;
	return 0;
}
