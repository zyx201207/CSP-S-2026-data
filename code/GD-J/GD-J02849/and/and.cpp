#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
long long max(long long a,long long b){
	return a>b?a:b;
}
struct number{
	long long past;
	std::string zo;
}w[200005];
void todo(number a){
	a.zo.clear();
	while(a.past!=0){
		if(a.past%2==0) a.zo+='0';
		else a.zo+='1';
		a.past/=2;
	}
//	std::cout<<a.zo<<"\n";
}
bool cmp(number a,number b){
	if(a.past>b.past) return false;
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long x,y,to=-1;
	scanf("%lld%lld",&x,&y);
	for(long long a=1;a<=x;a++){
		scanf("%lld",&w[a].past);
		todo(w[a]);
	}
	if(x==y){
		long long out=w[1].past;
		for(int a=2;a<=x;a++){
			out&=w[a].past;
		}
		printf("%lld",out);
		return 0;
	}
	if(y==1){
		long long out=-1;
		for(int a=2;a<=x;a++){
			out=max(out,w[a].past);
		}
		printf("%lld",out);
		return 0;
	}
	std::sort(w+1,w+x+1,cmp);
//	for(long long a=1;a<=x;a++){
//		std::cout<<w[a].zo<<"\n";
//	}
	for(long long a=x;a>=1;a--){
		long long now=w[a].past,get=1;
		for(long long r=x-1;r>=1;r--){
			for(unsigned long long t=w[r].zo.size()-1;t>=0;t--){
				if(w[a].zo[t]==w[r].zo[t]){
					now&=w[r].past;
					get++;
					break;
				}
			}
			if(get==y){
				break;
			}
		}
		if(get==y){
			to=max(to,now);
		}
		else to=w[1].past;
	}
	printf("%lld",to);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
