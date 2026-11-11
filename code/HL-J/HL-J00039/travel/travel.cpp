#include<bits/stdc++.h>
using namespace std;
long long ki=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,c2,s1,s2,sk1="",sk2="";
	bool k1=false,k2=false,k3=false;
	/*
	两张车票对应的座位是否在同一节车厢 
	两张车票对应的座位是否在同一节车厢的同一排 
	两张票对应的座位是否在同车厢的同一排且位于过道的同侧 
	两张车票对应的座位是否相邻。 
	*/
	cin>>c1>>s1>>c2>>s2;
	//分别表示小 R 的车票上的车厢号、座位号，以及小 X 的车票上的车厢号、座位号
	if(c1==c2){
		k1=true;
		cout<<1;
	}else{
		cout<<0;
		k1=false;
	}
	 
	for(int i=0;i<=1;i++){
		sk1+=s1[i];
	}
	for(int j=0;j<=1;j++){
		sk2+=s2[j];
	}
	if(k1){
		if(sk1==sk2){
			cout<<1;
			k2=true;
		}else{
			cout<<0;
			k2=false;
		}
	}else{cout<<0;}
	sk1=s1[2];
	sk2=s2[2];
	if(k1&&k2){
		if(sk1=="F"){
			if(sk2=="D"){
				cout<<1;
				k3=true;
			}else{
				cout<<0;
				k3=false;
			}
		} 
		if(sk1=="D"){
			if(sk2=="F"){
				cout<<1;
				k3=true;
			}else{
				cout<<0;
				k3=false;
			}
		}
		if(sk1=="A"){
			if(sk2=="B"||sk2=="C"){
				cout<<1;
				k3=true;
			}else{
				cout<<0;
				k3=false;
			}
		}
		if(sk1=="B"){
			if(sk2=="A"||sk2=="C"){
				cout<<1;
				k3=true;
			}else{
				cout<<0;
				k3=false;
			}
		}
		if(sk1=="C"){
			if(sk2=="B"||sk2=="A"){
				cout<<1;
				k3=true;
			}else{
				cout<<0;
				k3=false;
			}
		}
    }else{cout<<0;}
    
	
	
	
	
	
	if(k1&&k2&&k3){
	
	
		if(sk1=="F"){
			if(sk2=="D"){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		if(sk1=="D"){
			if(sk2=="F"){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		if(sk1=="A"){
			if(sk2=="B"){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		if(sk1=="B"){
			if(sk2=="A"||sk2=="C"){
				cout<<1;
			}else{
				cout<<0;
			}
		}
		if(sk1=="C"){
			if(sk2=="B"){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
}
