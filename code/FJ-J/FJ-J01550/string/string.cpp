#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,f,b,len,ans;
char c[200005];  
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	cin>>n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
//		cin>>a[i]>>c[i];
		scanf("%lld%s",&a[i],&c[i]); 
		sum+=a[i];
	}
	f=1;//处理到前f节 
	b=n;//处理到后b节 
	sum=sum/2;
//	cout<<sum<<endl;
	while(sum>=0){
		if(a[f]>sum){
			len=sum;
		}else{
			len=a[f];//比较的长度（一节） 
		}
		sum-=a[f];
		while(len>0){//将这一节长度比完
			if(len>=a[b]){//比最后一节长
				if(c[f]!=c[b]){//两节字母不同
					ans+=a[b];//加答案 
				}
				len-=a[b];//比完了 
				b--;//下一节 
			}else{//短于最后一节 
				if(c[f]!=c[b]){//两节字母不同
					ans+=len;//加答案 
				}
				a[b]-=len;//扣掉已经比较的长度 
				len=0;//清空长度
			}
//			cout<<ans<<endl;
		} 
		f++; 
	}
//	cout<<ans;
	printf("%lld",ans);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<endl;
//	}
}
/*
总体思路：
统计总字符数/2
前后比较 
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
