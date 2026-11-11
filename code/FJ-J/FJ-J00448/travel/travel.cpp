#include<bits/stdc++.h>
using namespace std;
int a,b;
string aa,bb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&a);
	cin>>aa;
	scanf("%d",&b);
	cin>>bb;	
	if(a==b){
		if(aa[0]==bb[0]&&aa[1]==bb[1]){
			if((aa[2]<='C'&&bb[2]<='C')||(aa[2]>='D'&&bb[2]>='D')){
				if(abs(aa[2]-bb[2])==1)printf("1111");
				else printf("1110");
			}
			else printf("1100");
		}
		else printf("1000");
	}
	else printf("0000");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

