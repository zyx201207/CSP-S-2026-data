//GZ-J00568 遵义市第四初级中学 罗俊毅 
#include<iostream>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string use[26][10]={};
	int a;
	cin>>a;
	int b,lens;
	char c;
	string s1="",s2="";
	for(int i=0;i<a;i++){
		cin>>b>>c;
		int lenb;
		int shiyi=b/1000000000,yi=b/100000000,qianwan=b/10000000,baiwan=b/1000000,shiwan=b/100000,wan=b/10000,qian=b/1000,bai=b/100,shi=b/10,ge=b%10;
		if(shiyi>0)lenb=9;
		else if(yi>0)lenb=8;
		else if(qianwan>0)lenb=7;
		else if(baiwan>0)lenb=6;
		else if(shiwan>0)lenb=5;
		else if(wan>0)lenb=4;
		else if(qian>0)lenb=3;
		else if(bai>0)lenb=2;
		else if(shi>0)lenb=1;
		else lenb=0;
		int casc=(c-'a');
		if(use[casc][lenb]==""){
			use[casc][0]=c;
			for(int i=1;i<=lenb;i++){
				if(use[casc][i]==""){
					for(int j=0;j<10;j++){
						use[casc][i]+=use[casc][i-1];
					}
				}
			}
		}
		lens+=b;
		while(shiyi--){
			s1+=use[casc][9];
		}
		while(yi--){
			s1+=use[casc][8];
		}
		while(qianwan--){
			s1+=use[casc][7];
		}
		while(baiwan--){
			s1+=use[casc][6];
		}
		while(shiwan--){
			s1+=use[casc][5];
		}
		while(wan--){
			s1+=use[casc][4];
		}
		while(qian--){
			s1+=use[casc][3];
		}
		while(bai--){
			s1+=use[casc][2];
		}
		while(shi--){
			s1+=use[casc][1];
		}
		while(ge--){
			s1+=use[casc][0];
		}
	}
	for(int i=lens-1;i>=0;i--){
		s2+=s1[i];
	}
	int sum=0;
	for(int i=0;i<lens;i++){
		if(s1[i]!=s2[i]){
			sum++;
			s1[lens-i-1]=s1[i];
			s2[i]=s1[i];
		}
	}
	printf("%d",sum);
	return 0;
}
