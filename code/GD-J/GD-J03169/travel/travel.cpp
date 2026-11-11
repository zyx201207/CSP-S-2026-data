#include<bits/stdc++.h>
using namespace std;
struct chengke{
	int chexiang;
	int pai;
	char zuo;
};
chengke a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>a.chexiang>>a.pai>>a.zuo;
	cin>>b.chexiang>>b.pai>>b.zuo;
	if(a.chexiang==b.chexiang){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a.pai==b.pai&&a.chexiang==b.chexiang){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='A'&&b.zuo=='B'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='B'&&b.zuo=='A'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='B'&&b.zuo=='C'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='C'&&b.zuo=='B'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='A'&&b.zuo=='C'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='C'&&b.zuo=='A'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='D'&&b.zuo=='F'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='F'&&b.zuo=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='A'&&b.zuo=='B'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='B'&&b.zuo=='A'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='B'&&b.zuo=='C'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='C'&&b.zuo=='B'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='D'&&b.zuo=='F'){
		cout<<1;
	}else if(a.pai==b.pai&&a.chexiang==b.chexiang&&a.zuo=='F'&&b.zuo=='D'){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
