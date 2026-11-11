//准考证号：GZ-J00004 姓名：龚兴漩 
#include<bits/stdc++.h>

int sl[200005];
char sc[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int sn;
	scanf("%d",&sn);
	for(int i=0;i<sn;i++)
		scanf("%d %c",&sl[i],&sc[i]);
	int fr=0,lr=sn-1;
	long long cg=0;
	bool fb=false;
	while(fr<lr){
		int tl=0;
		if(sl[fr]<sl[lr]){
			tl=sl[fr];
			fb=false;
		}
		else{
			tl=sl[lr];
			fb=true;
		}
		if(sc[fr]!=sc[lr]){
			cg+=tl;
			if(fb){
				sl[fr]=sl[fr]-sl[lr];
				lr--;
			}
			else{
				sl[lr]=sl[lr]-sl[fr];
				fr++;
			}
		}
		else{
			if(fb){
				sl[fr]=sl[fr]-sl[lr];
				lr--;
			}
			else{
				sl[lr]=sl[lr]-sl[fr];
				fr++;
			}
		}
	}
	printf("%lld",cg);
	return 0;
}
