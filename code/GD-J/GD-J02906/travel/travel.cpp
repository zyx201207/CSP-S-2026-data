#include<iostream>//travel
using namespace std;
string c,s,cc,ss;//c=c1s=s1
int a,q,aa,qq;
char p,g;
int main(){
	freopen("travel.in","r",stdin);//别住释！！！！
	freopen("travel.out","w",stdout);//别住释！！！！ 
	cin>>c>>s>>cc>>ss;
	a=(c[0]-48)*10+(c[1]-48);
	aa=(cc[0]-48)*10+(cc[1]-48);
	
	if(a!=aa){
		cout<<0<<0<<0<<0;
		return 0;
	}else{
		cout<<1;
	}
	q=(s[0]-48)*10+(s[1]-48);
	qq=(ss[0]-48)*10+(ss[1]-48);
	if(q!=qq){
		cout<<0<<0<<0;
		return 0;
	}else{
		cout<<1;
	}
	p=s[2];
	g=ss[2];
	if((p!='D'&&p!='F'&&g!='D'&&g!='F')||(p!='C'&&p!='B'&&p!='A'&&g!='A'&&g!='B'&&g!='C')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if((g+1==p||g-1==p)&&(p!='D'||p!='F'||g!='D'||g!='F')){
		cout<<1;
	}else if((p=='D'&&g=='F')||(p=='F'&&g=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
