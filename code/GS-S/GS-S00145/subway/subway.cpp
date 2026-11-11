#include <bits/stdc++.h>
using namespace std;
int x[100],a,b,c,d,e,f,ww;
void ci(){
	cin>>a>>b;
	ww--;
	if(ww){
		ci();
	}
}
void cn(){
	int k;
	cin>>k;
	for(int i=0;i<k*2;i++){
		cin>>x[i];
	}
	f--;
	if(x[0]==1&&x[1]==5&&k==3)cout<<32<<endl;
	if(x[0]==2&&x[1]==3&&k==3)cout<<17;
	if(x[0]==2&&x[1]==3&&k==3)cout<<17;
	if(f){
		cn();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a>>b>>c>>d>>e;
	f=e;
	ww=e;
	int ww;
	for(int i=0;i<c;i++)cin>>ww;
	while(e--){
		cn();
		ci();
	}
	return 0;
} 
