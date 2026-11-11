#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	char u,y;
	string a,e,j,cnt,cnta;
	int b,n;
	for(int s=1;s<=1;s++){
		cin>>n;
	}
	for(int r=1;r<=1;r++){
		cin>>a;
	}	
	for(int w=1;w<=1;w++){
		cin>>b;
	}
	for(int m=1;m<=1;m++){
		cin>>e;
	}
	if(n==b){
		cout<<"1";
	for(int j=0;j<=2;j++){
		if(e[0]<'9'||e[0]>'0'){
			cnt+=e[0];
			}
		}
	for(int h=0;h<=2;h++){
		if(a[0]<'9'||a[0]>'0'){
			cnta+=a[0];
		}
	}
	if(cnta==cnt){
	cout<<"1";
		for(int z=0;z<=1;z++){
	if(e[0]<'Z'||e[0]>'A'){
		u=e[0];
		}}
	for(int x=0;x<=1;x++){
		if(a[0]<'Z'||a[0]>'A'){
		y=a[0];
			}
		}
	if(u<'F'||u>'D'||y<'F'||y>'D'||cnta==cnt){
		cout<<"1";
		if(u<'C'||u>'A'||y<'C'||y>'A'){
			if(u=='C'||y=='B'){
				cout<<"1";
			}if(u=='B'||y=='C'){
				cout<<"1";
			}if(u=='A'||y=='B'){
				cout<<"1";
			}if(u=='C'||y=='B'){
				cout<<"1";
		}	if(u=='B'||y=='A'){
				cout<<"1";
		}	if(u=='B'||y=='C'){
				cout<<"1";
		}

	    
}
		
		 }else{
		 	cout<<"0";
		 }if(u<'C'||u>'A'||y<'C'||y>'A'||cnta==cnt){
		 	
		 	
		 	if(u<'C'||u>'A'||y<'C'||y>'A'){
			if(u=='C'||y=='B'){
				cout<<"1";
			}if(u=='B'||y=='C'){
				cout<<"1";
			}if(u=='A'||y=='B'){
				cout<<"1";
			}if(u=='C'||y=='B'){
				cout<<"1";
		}	if(u=='B'||y=='A'){
				cout<<"1";
		}	if(u=='B'||y=='C'){
				cout<<"1";
		}

	    
}
}else{
			cout<<"0000";
			return 0;
		}
	
	}else{
			cout<<"0";
		}

		 }else{
			cout<<"0";
		}
		
	return 0;

}

