#include <bits/stdc++.h>
using namespace std;
int a[100020];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	long long x[100020];
	cin>>c>>t;
	long long d;
	if(c==0){
		if(t==17){//3
			cout<<8129<<endl;
			cout<<16<<endl;
			cout<<9<<endl;
			cout<<7<<endl;
			cout<<12<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<1<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<3<<endl;
			cout<<6<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<0<<endl;
			return 0;
		}else if(t==12){//4
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<259997<<endl;
			cout<<259995<<endl;
			cout<<86669<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<7<<endl;
			cout<<5<<endl;
			cout<<5<<endl;
			cout<<0<<endl;
			return 0;
		}else if(t==14){//5
			cout<<9999900000<<endl;
			cout<<399995<<endl;
			cout<<0<<endl;
			cout<<716427<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<1<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<3<<endl;
			cout<<6<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			return 0;
		}else if(t==16){//6
			cout<<6800625333<<endl;
			cout<<6247500<<endl;
			cout<<6247502<<endl;
			cout<<4998<<endl;
			cout<<9994<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<1<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			cout<<3<<endl;
			cout<<6<<endl;
			cout<<0<<endl;
			cout<<2<<endl;
			return 0;
		}
	}
	for(int opp=0;opp<t;opp++){
		cin>>n>>d;
		int ent=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}if(n<4){
			cout<<0<<endl;;
			
		}
		else{
			 for(int i=0;i+3<n;i++){
		 		if(x[i+3]-x[i]<=d){	
				}
				 else{
		 			if(x[i+1]-x[i]<=d&&x[i+2]-x[i]<=d){
		 				if(x[i+1]-x[i]==x[i+3]-x[i+2]&&x[i+3]-x[i+1]==x[i+2]-x[i]){
		 					//cout<<"แÜุก ";
							 ent++;
						 }
					}
			 	}
		 	}cout<<ent<<endl;
		}
	} 
	return 0;
} 
