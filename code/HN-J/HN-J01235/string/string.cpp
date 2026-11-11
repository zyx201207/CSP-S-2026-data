#include<iostream>
#define int long long
char c;
int n,sum=0,num=0;
long long ans=0,s[100001];
int a[100001],b[100001];
int search(int num){
	int now=num,i;
	for(i=1;i<=n;++i){
		if(now<=a[i]) return i;
		now-=a[i];
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld %c\n",a+i,&c);
		b[i]=signed(c),sum+=a[i];
		s[i]=s[i-1]+a[i];
//		printf("%lld %lld\n",a[i],b[i]);
	}
	if(sum%2){
		num=(sum+1)/2;
		--a[search(num)];
		--sum;
	}
	int a1=search(sum/2),b1=search(sum/2+1),pos1=sum/2,pos=sum/2+1;
	if(a1==b1){
		int s1=pos1-a[a1-1],s2=a[a1]-pos1;
		if(s1>s2) ++b1;
		else if(s1<s2) --a1;
			 else --a1,++b1;
		a[a1]-=std::min(s1,s2)*2;
	}
	while(a1!=0&&b1!=n+1){
		int s1=a[a1],s2=a[b1];
//		printf("%lld %lld %lld %lld\n",a1,s1,b1,s2);
		if(s1>s2){
//			printf("1\n");
			if(b[a1]!=b[b1]) ans+=s2;
			++b1;
			a[a1]-=s2;
		}
		if(s1<s2){
//			printf("2\n");
			if(b[a1]!=b[b1]) ans+=s1;
			--a1;
			a[b1]-=s1;
		}
		if(s1==s2){
//			printf("3\n");
			if(b[a1]!=b[b1]) ans+=s1;
			++b1,--a1;
		}
//		printf("%lld\n",ans);
	}
	printf("%lld",ans);
	return 0;
}
