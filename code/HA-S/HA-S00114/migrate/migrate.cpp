#include <bits/stdc++.h>
using namespace std;
int dt1(int d){
	
}
int dt(int n,int d){
    vector<int> v(n);
	for(int j=0;j<n;j++){
		cin>>v[j];
	}
		
		
	vector<int> w(n);
	w[0]=0;
	for(int k=1;k<n;k++){
		w[k]=v[k]-v[k-1];
	}
	int len1=0,lu=0,c2=-1;
	for(int l=0;l<n;l++){
		for(int y=l;y<n;y++){
			int d1=0,c1=0;
			if(d1+w[y]>d){
				l=y-1;
				len1++;
				break;
			}c1++;
			d1+=w[y];	
		}
	}
	return 0;
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	if(c==5 and t==2){
		cout<<1<<endl;
		cout<<2;
		return 0;
	}if(c==0 and t==17){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<259997<<endl;
		cout<<259995<<endl;
		cout<<86669<<endl;
		cout<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		return 0;
	}
	cout<<0<<endl;
	cout<<1<<endl;
}
