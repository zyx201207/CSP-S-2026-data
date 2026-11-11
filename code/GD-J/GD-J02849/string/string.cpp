#include<cstdio>
#include<cmath>
struct have{
	long long number;
	char what;
}string[200005];
long long min(long long a,long long b){
	return a<b?a:b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long x,all=0,want=0,left=1,right;
	scanf("%lld",&x);
	if(x==1){
		printf("0");
		return 0;
	}
	right=x;
	for(long long a=1;a<=x;a++){
		scanf("%lld %c",&string[a].number,&string[a].what);
		all+=string[a].number;
	}
//	for(long long a=1;a<=x;a++){
//		printf("%lld %c\n",string[a].number,string[a].what);
//		all+=string[a].number;
//	}
	while(left<right){
//		printf("A %lld %lld\n",left,right);
//		for(long long a=1;a<=x;a++){
//			printf("B %lld %lld %c\n",a,string[a].number,string[a].what);
//		}
		if(string[left].what==string[right].what){
			int to=min(string[left].number,string[right].number);
			string[left].number-=to,string[right].number-=to;
			if(string[left].number==0) left++;
			if(string[right].number==0) right--;
		}
		else{
			int to=min(string[left].number,string[right].number);
			if(to==string[left].number){
				string[left].what=string[right].what;
			}
			else{
				string[right].what=string[left].what;
			}
			want+=to;
			continue;
		}
	}
	printf("%lld",want);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
