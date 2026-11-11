#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	//p1
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000\n";
		exit(0);
	}
	
	//p2
	string p1=s1.substr(0,2);
	string p2=s2.substr(0,2);
	if(p1==p2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	//p3
	char w1=s1[2];
	char w2=s2[2];
//	cout<<w1<<" "<<w2<<endl;
	int flag=0;
	if(p1!=p2){
		cout<<0;
	}else{
		if(w1=='A'||w1=='B'||w1=='C'){
			if(w2=='D'||w2=='F'){
				cout<<0;
			}else{
				cout<<1;flag=1;
			}
		}else{
			if(w2=='D'||w2=='F'){
				cout<<1;flag=2;
			}else{
				cout<<0;
			}
		}
	}
	
	//p4
	if(flag==0){
		cout<<0;
	}else if(flag==2){
		cout<<1;
	}else if(flag==1){
		if((w1=='A'&&w2=='C')||(w1=='C'&&w2=='A')){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	cout<<"\n";
	
	return 0;
}
