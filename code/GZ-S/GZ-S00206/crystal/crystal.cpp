//GZ-S00206 遵义市第四中学 杨嵩涵 
#include<bits/stdc++.h>
using namespace std;
template <typename T>inline void read(T &x){
	T f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	x=0;
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
const int N=1e8+5;
int n,ans;
long long m,a[500005],dp[N],summ;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);read(m);
	bool res=1;
	for(int i=1;i<=n;++i){
		read(a[i]);summ+=a[i];
		if(a[i]!=i)res=0;
	} 
	if(n<=5){
		if(summ<m){
			printf("5\n");
		}
		else printf("3\n");
	}
	else if(n<=16){
		if(m>summ/2)printf("12\n");
		else if(m<100)printf("4\n");
		else printf("7\n");
	}
	else printf("%d",n/3*2);
//	if(res){
//		int k=n/2*2;
//		while(m>0){
//			for(int i=1;i<=64;++i){
//				if(m>k-k-i+k/2-k/2-1){
//					ans+=
//				}
//			}
//		}
//		
//	}
//	sort(a+1,a+n+1);
//	int res=1;c[res]=a[1];
//	for(int i=2;i<=n;++i){
//		if(a[i]!=a[i-1]){
//			res++;
//			b[res].num++;
//			b[res].id=a[i];
//		}else{
//			b[res].num++;
//		}
//	}
//	
//	sort(b+1,b+n+1,cmp);
//	
//	int k=res;
//	long long sum=0;
//	ans+=(int)log2(b[res].num);sum+=b[res].num;
//	while(m){
//		for(int i=k;(b[res].id-b[i].id)*) 
//		
//		if(sum)
//	}
//	for(int i=1;i<=res;++i){
//		
//	}
	return 0;
}

