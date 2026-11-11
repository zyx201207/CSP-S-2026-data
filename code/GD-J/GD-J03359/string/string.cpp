#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans,tmp;
long long a[200010];
char q;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&tmp,&q);
		if(q==c[k]){
			//如果相同则合并 
			a[k]+=tmp;
		}else{
			//不同则记录 
			k++;
			a[k]=tmp;
			c[k]=q;
		}
	}
	for(int i=1,j=k;i<j;){ 
		//改字符较少的 
		if(a[i]>a[j]){
			tmp=0;
			//看看要用几个子段来修改 
			while(tmp+a[j]<=a[i]){
				tmp+=a[j];
				if(c[j]!=c[i]){
					//不同则加入答案 
					ans+=a[j];
				}
				j--;
			}
			if(c[j]!=c[i]){
				//不同则加入答案 
				ans+=(a[i]-tmp);
			}
			if(tmp+a[j]>a[i]){
				//多余的记录
				a[j]-=(a[i]-tmp);
			}
			i++;
		}else{
			//同理 
			tmp=0;
			while(tmp+a[i]<=a[j]){
				tmp+=a[i];
				if(c[i]!=c[j]){
					ans+=a[i];
				} 
				i++;
			}
			if(c[i]!=c[j]){
				ans+=(a[j]-tmp);
			}
			if(tmp+a[i]>a[j]){
				a[i]-=(a[j]-tmp);
			}
			j--;
		}
	}
	printf("%lld",ans);
	return 0;
}
