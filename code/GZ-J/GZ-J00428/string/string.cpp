//侯欣言  GZ-J00428 兴义市弘毅中学
#include <bits/stdc++.h>
long long sum=0,sum1=0;
long long  n;
char zimu[500000];
long long ge[500000];
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld %c",&ge[i],&zimu[i]);
		sum+=ge[i];
	}
	long long r=0;
	long long l1=0,l2=n-1;
	while(r*2<sum){
		if(zimu[l1]==zimu[l2]){
			if(ge[l1]<=ge[l2]){
			r+=ge[l1];
			ge[l2]-=ge[l1];
			l1++;	
		}else{
			r+=ge[l2];
			ge[l1]-=ge[l2];
			l2--;
		}
	}else{
		if(ge[l1]<=ge[l2]){
			sum1+=ge[l1];
			r+=ge[l1];
			ge[l2]-=ge[l1];
			l1++;
		}else{
			sum1+=ge[l2];
			r+=ge[l2];
			ge[l1]-=ge[l2];
			l2--;
		}
	}
}
printf("%lld",sum1);
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
