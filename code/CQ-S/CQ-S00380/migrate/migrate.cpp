/*
HAPPY AFO :)

int(max(0.0,min(1.0*g1,g1*0.8*(1.0*min(1.0,1.1-1.0*f2/(f2+100)))+g1*0.2)))

#include<bits/stdc++.h>
using namespace std;
long long xx2=10000,gg2=1000,ff2=200;
long long x1=10000,g1=1000,f1=200,x2=10000,g2=1000,f2=200;
int ks(int g1,int f2){
	return int(max(0.0,min(1.0*g1,g1*0.8*(1.0*min(1.0,1.1-1.0*f2/(f2+100)))+g1*0.2)));
}
//1+x   2+g   3+f 
int act1(){
	int k;
	cin>>k;
	return k;
}
int act2(){
	int k=rand()%4+1;
	if(f2<f1){
		return 3;
	}
	if(x2<x1){
		return 1;
	}
	return k;
}
signed main(){
	srand(time(0));
//	cin>>x1>>g1>>f1>>x2>>g2>>f2;
//	cout<<ks(g1,f2);
	while(x1>=0){
		while(x1>=0&&x2>=0){
			int c1=act1();
			int c2=act2();
			if(c1==1) x1+=f1*0.7;
			if(c2==1) x2+=f2*0.7;
			if(c1==2) g1*=1.05;
			if(c2==2) g2*=1.05;
			if(c1==3) f1*=1.1;
			if(c2==3) f2*=1.1;
			cout<<x1<<" "<<g1<<" "<<f1<<"\n"<<x2<<" "<<g2<<" "<<f2<<"\n";
			if(c1==4){
				cout<<"1->2  "<<ks(g1,f2)<<"\n";
				x2-=ks(g1,f2);
			}
			if(c2==4){
				cout<<"2->1  "<<ks(g2,f1)<<"\n";
				x1-=ks(g2,f1);
			}
			cout<<x1<<" "<<g1<<" "<<f1<<"\n"<<x2<<" "<<g2<<" "<<f2<<"\n\n";
		}
		_sleep(1000);
		cout<<"\n\n\n\n\n";
		xx2*=2.0;
		gg2*=1.3;
		ff2*=1.5;
		x2=xx2,g2=gg2,f2=ff2;
		x1+=10000;
		int ss=rand()%3+1;
		if(ss==1){
			x1+=10000;
			x1*=2;
		}
		if(ss==2){
			g1+=1000;
			g1*=2;
		}
		if(ss==3){
			f1+=200;
			f1*=2; 
		}
		cout<<x1<<" "<<g1<<" "<<f1<<"\n"<<x2<<" "<<g2<<" "<<f2<<"\n\n\n";
	}
	
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	return 0;
}
