#include<bits/stdc++.h>

using namespace std;
int c,t,n,d,lj,dy=1,cnt=0,l,j;
long long x[2000005],p[2000005];
int main(){
	ifstream("migrate.in");
	ofstream("migrate.out");
	cin>>c>>t;
	p[0]=0;
	cnt=0;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			p[j]=p[j]-p[j-1];
		}
		cnt=0;
		l=1;
		while(l<n){
			j=l+1;
			dy=2;
			lj=x[j]-x[l];
			while(lj<=d&&j<=n){
				lj+=x[j]-x[j-1];
				if(lj>d)break;
				dy++;
				j++;
			}
			if(dy>2){
				if(dy>=4){
					if(l>1)cnt++;
					if(j<n)cnt++;
				}
				cnt+=dy-2;
			}
			l+=dy;
			lj=0;
		}
		cout<<cnt<<endl;
	}
} 
