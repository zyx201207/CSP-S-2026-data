#including<bits/stdc++.h>
using namespace std;
int main()
{
	freeopen("crystal.in","r",stdin);
	freeopen("crystal.out","w",stdout);
	int n,m,a,x,d=1,e=0;
	cin>>n>>m;
	int b[n]={0},c[n*n]={0};
	for (int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(b[i]<b[j]){
				a=b[i];
				b[i]=b[j];
				b[j]=a;
			}
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n){
		x=m;
			for(int k=i;k<j;k++){
				if(b[k]+x>=b[j]){x-=b[k]+x-b[j];c[i+j]+=1;}
				else i++;
			}
		}
	}
	while(c[d]!='\0'){
		e=max(c[d-1],c[d]);
		d++;
	}
	cout<<e;
}
