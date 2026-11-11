#include<bits/stdc++.h>
#define du double
#define ll long long
using namespace std;
const int M=1e5+5;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int a,b;
	string aa,bb;
	cin>>a>>aa>>b>>bb;
	//提取部分
	int xa,xb,ya,yb;
	xa=(aa[0]-'0')*10+(aa[1]-'0')*1;
	xb=(bb[0]-'0')*10+(bb[1]-'0')*1;//排数 
	ya=aa[2]-'A'+1;yb=bb[2]-'A'+1;//座位号 
	if(a!=b){
		cout<<"0000";
	}else if(xa!=xb){
		cout<<1000;
	}else{
		if(ya>yb)swap(ya,yb);
		if(ya==1&&yb==2){
			cout<<1111;
		}else if(ya==2&&yb==3){
			cout<<1111;
		}else if(ya==4&&yb==6){
			cout<<1111;
		}else if(ya==1&&yb==3){
			cout<<1110;
		}else if(ya<=3&&yb>=4){
			cout<<1100;
		}
	}
	return 0;
}
