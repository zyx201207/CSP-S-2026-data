#include<bits/stdc++.h>
using namespace std;
struct f{
	long long s;
	char zl;
}sz1[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>sz1[i].s>>sz1[i].zl;
	}
	long long cs=0,ys=0;
	bool fx=0;
	for(int i=0;i<a/2;i++){
		if(sz1[i].zl!=sz1[a-1-i].zl){
			if(fx==0){
				sz1[i].s+=ys;
			}
			else{
				sz1[a-i-1].s+=ys;
			}
			cs+=min(sz1[i].s,sz1[a-i-1].s);
			ys=0;
			ys+=abs(sz1[i].s-sz1[a-i-1].s);
		}
		else{
			if(sz1[i].s>sz1[a-i-1].s){
				fx=0;
			}
			else{
				fx=1;
			}
	}
}
cout<<cs;
return 0;
}
 
